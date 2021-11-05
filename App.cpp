//
// Created by Piou on 29/10/2021.
/*
 _______   _                   
|_   __ \ (_)                  
  | |__) |__   .--.   __   _   
  |  ___/[  |/ .'`\ \[  | | |  
 _| |_    | || \__. | | \_/ |, 
|_____|  [___]'.__.'  '.__.'_/
 pierrick.gallois.lacroix@gmail.com
*/
//

#include "App.hpp"

// std
#include <array>
#include <stdexcept>

namespace grp {
    App::App() {
        loadModels();
        createPipelineLayout();
        recreateSwapChain();
        createCommandBuffers();
    }

    App::~App() {
        vkDestroyPipelineLayout(grpDevice.device(), pipelineLayout, nullptr);
    }

    void App::run() {
        while (!grpWindow.shouldClose()) {
            glfwPollEvents();
            drawFrame();
        }

        vkDeviceWaitIdle(grpDevice.device());
    }

    void App::createPipelineLayout() {
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = 0;
        pipelineLayoutInfo.pSetLayouts = nullptr;
        pipelineLayoutInfo.pushConstantRangeCount = 0;
        pipelineLayoutInfo.pPushConstantRanges = nullptr;
        if (vkCreatePipelineLayout(grpDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
            throw std::runtime_error("failed to create pipeline layout!");
        }
    }

    void App::createPipeline() {
        assert(grpSwapChain != nullptr && "Can not create pipeline before swapchain");
        assert(pipelineLayout != nullptr && "Can not create pipeline before pipeline layout");

        PipelineConfigInfo pipelineConfig{};
        GrpPipeline::defaultPipelineConfigInfo(pipelineConfig);
        pipelineConfig.renderPass = grpSwapChain->getRenderPass();
        pipelineConfig.pipelineLayout = pipelineLayout;
        grpPipeline = std::make_unique<GrpPipeline>(grpDevice,
                                                    "..\\shaders\\basic_shader.vert.spv",
                                                    "..\\shaders\\basic_shader.frag.spv",
                                                    pipelineConfig);
    }

    void App::recreateSwapChain() {
        auto extent = grpWindow.getExtent();
        while (extent.width == 0 || extent.height == 0) {
            extent = grpWindow.getExtent();
            glfwWaitEvents();
        }

        vkDeviceWaitIdle(grpDevice.device());

        if (grpSwapChain == nullptr) {
            grpSwapChain = std::make_unique<GrpSwapChain>(grpDevice, extent);
        } else {
            grpSwapChain = std::make_unique<GrpSwapChain>(grpDevice, extent, std::move(grpSwapChain));
            if (grpSwapChain->imageCount() != commandBuffers.size()) {
                freeCommandBuffers();
                createCommandBuffers();
            }
        }
        createPipeline();
    }

    void App::createCommandBuffers() {
        commandBuffers.resize(grpSwapChain->imageCount());
        VkCommandBufferAllocateInfo allocInfo{};
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandPool = grpDevice.getCommandPool();
        allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());
        if (vkAllocateCommandBuffers(grpDevice.device(), &allocInfo, commandBuffers.data()) != VK_SUCCESS) {
            throw std::runtime_error("failed to allocate command buffers!");
        }
        for (int i = 0; i < commandBuffers.size(); i++) {

        }
    }

    void App::recordCommandBuffer(int imageIndex) {
        VkCommandBufferBeginInfo beginInfo{};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        if (vkBeginCommandBuffer(commandBuffers[imageIndex], &beginInfo) != VK_SUCCESS) {
            throw std::runtime_error("failed to begin recording command buffer!");
        }
        VkRenderPassBeginInfo renderPassInfo{};
        renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        renderPassInfo.renderPass = grpSwapChain->getRenderPass();
        renderPassInfo.framebuffer = grpSwapChain->getFrameBuffer(imageIndex);

        renderPassInfo.renderArea.offset = {0, 0};
        renderPassInfo.renderArea.extent = grpSwapChain->getSwapChainExtent();

        std::array<VkClearValue, 2> clearValues{};
        clearValues[0].color = {0.1f, 0.1f, 0.1f, 1.0f};
        clearValues[1].depthStencil = {1.0f, 0};
        renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
        renderPassInfo.pClearValues = clearValues.data();

        vkCmdBeginRenderPass(commandBuffers[imageIndex], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

        VkViewport viewport{};
        viewport.x = 0.0f;
        viewport.y = 0.0f;
        viewport.width = static_cast<float>(grpSwapChain->getSwapChainExtent().width);
        viewport.height = static_cast<float>(grpSwapChain->getSwapChainExtent().height);
        viewport.minDepth = 0.0f;
        viewport.maxDepth = 1.0f;
        VkRect2D scissor{{0, 0}, grpSwapChain->getSwapChainExtent()};
        vkCmdSetViewport(commandBuffers[imageIndex], 0, 1, &viewport);
        vkCmdSetScissor(commandBuffers[imageIndex], 0, 1, &scissor);

        grpPipeline->bind(commandBuffers[imageIndex]);
        grpModel->bind(commandBuffers[imageIndex]);
        grpModel->draw(commandBuffers[imageIndex]);

        vkCmdEndRenderPass(commandBuffers[imageIndex]);
        if (vkEndCommandBuffer(commandBuffers[imageIndex]) != VK_SUCCESS) {
            throw std::runtime_error("failed to record command buffer!");
        }
    }

    void App::drawFrame() {
        uint32_t imageIndex;
        auto result = grpSwapChain->acquireNextImage(&imageIndex);

        if (result == VK_ERROR_OUT_OF_DATE_KHR) {
            recreateSwapChain();
            return;
        }

        if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
            throw std::runtime_error("Failed to acquire swap chain image");
        }

        recordCommandBuffer(imageIndex);
        result = grpSwapChain->submitCommandBuffers(&commandBuffers[imageIndex], &imageIndex);
        if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || grpWindow.wasWindowResized()) {
            grpWindow.resetWindowResizedFlag();
            recreateSwapChain();
            return;
        }
        if (result != VK_SUCCESS) {
            throw std::runtime_error("Failed to present swap chain image");
        }
    }

    void App::loadModels() {
        std::vector<GrpModel::Vertex> vertices{{{0.0f,  -0.5f}, {1.0f, 0.0f, 0.0f}},
                                               {{0.5f,  0.5f},  {0.0f, 1.0f, 0.0f}},
                                               {{-0.5f, 0.5f},  {0.0f, 0.0f, 1.0f}}};

        grpModel = std::make_unique<GrpModel>(grpDevice, vertices);
    }

    void App::freeCommandBuffers() {
        vkFreeCommandBuffers(grpDevice.device(),
                             grpDevice.getCommandPool(),
                             static_cast<uint32_t>(commandBuffers.size()),
                             commandBuffers.data());
        commandBuffers.clear();
    }
}