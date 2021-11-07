//
// Created by Piou on 07/11/2021.
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

#include "grp_renderer.hpp"

// std
#include <array>
#include <cassert>
#include <stdexcept>

namespace grp {

    GrpRenderer::GrpRenderer(GrpWindow &window, GrpDevice &device) : grpWindow(window), grpDevice(device) {
        recreateSwapChain();
        createCommandBuffers();
    }

    GrpRenderer::~GrpRenderer() {
        freeCommandBuffers();
    }

    void GrpRenderer::recreateSwapChain() {
        auto extent = grpWindow.getExtent();
        while (extent.width == 0 || extent.height == 0) {
            extent = grpWindow.getExtent();
            glfwWaitEvents();
        }

        vkDeviceWaitIdle(grpDevice.device());

        if (grpSwapChain == nullptr) {
            grpSwapChain = std::make_unique<GrpSwapChain>(grpDevice, extent);
        } else {
            std::shared_ptr<GrpSwapChain> oldSwapChain = std::move(grpSwapChain);
            grpSwapChain = std::make_unique<GrpSwapChain>(grpDevice, extent, oldSwapChain);

            if(!oldSwapChain->compareSwapFormats(*grpSwapChain.get())) {
                throw std::runtime_error("Swap chain formats has changed !");
            }
        }
        // LATER
    }

    void GrpRenderer::createCommandBuffers() {
        commandBuffers.resize(GrpSwapChain::MAX_FRAMES_IN_FLIGHT);
        VkCommandBufferAllocateInfo allocInfo{};
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandPool = grpDevice.getCommandPool();
        allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());
        if (vkAllocateCommandBuffers(grpDevice.device(), &allocInfo, commandBuffers.data()) != VK_SUCCESS) {
            throw std::runtime_error("failed to allocate command buffers!");
        }
    }

    void GrpRenderer::freeCommandBuffers() {
        vkFreeCommandBuffers(grpDevice.device(),
                             grpDevice.getCommandPool(),
                             static_cast<uint32_t>(commandBuffers.size()),
                             commandBuffers.data());
        commandBuffers.clear();
    }

    VkCommandBuffer GrpRenderer::beginFrame() {
        assert(!isFrameStarted && "Can't call beginFrame wile already in progress");
        auto result = grpSwapChain->acquireNextImage(&currentImageIndex);

        if (result == VK_ERROR_OUT_OF_DATE_KHR) {
            recreateSwapChain();
            return nullptr;
        }

        if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
            throw std::runtime_error("Failed to acquire swap chain image");
        }

        isFrameStarted = true;

        auto commandBuffer = getCurrentCommandBuffer();
        VkCommandBufferBeginInfo beginInfo{};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        if (vkBeginCommandBuffer(commandBuffer, &beginInfo) != VK_SUCCESS) {
            throw std::runtime_error("failed to begin recording command buffer!");
        }

        return commandBuffer;
    }

    void GrpRenderer::endFrame() {
        assert(isFrameStarted && "Can't call endFrame  while frame is not in progress");
        auto commandBuffer = getCurrentCommandBuffer();

        if (vkEndCommandBuffer(commandBuffer) != VK_SUCCESS) {
            throw std::runtime_error("failed to record command buffer!");
        }
        auto result = grpSwapChain->submitCommandBuffers(&commandBuffer, &currentImageIndex);
        if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || grpWindow.wasWindowResized()) {
            grpWindow.resetWindowResizedFlag();
            recreateSwapChain();
        }
        else if (result != VK_SUCCESS) {
            throw std::runtime_error("Failed to present swap chain image");
        }
        isFrameStarted = false;
        currentFrameIndex = (currentFrameIndex + 1) % GrpSwapChain::MAX_FRAMES_IN_FLIGHT;
    }

    void GrpRenderer::beginSwapChainRenderPass(VkCommandBuffer commandBuffer) {
        assert(isFrameStarted && "Can't call beginSwapChainRenderPass  while frame is not in progress");
        assert(commandBuffer == getCurrentCommandBuffer() &&
               "Can't begin render pass on command buffer from a different frame");

        VkRenderPassBeginInfo renderPassInfo{};
        renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        renderPassInfo.renderPass = grpSwapChain->getRenderPass();
        renderPassInfo.framebuffer = grpSwapChain->getFrameBuffer(currentImageIndex);

        renderPassInfo.renderArea.offset = {0, 0};
        renderPassInfo.renderArea.extent = grpSwapChain->getSwapChainExtent();

        std::array<VkClearValue, 2> clearValues{};
        clearValues[0].color = {0.01f, 0.01f, 0.01f, 1.0f};
        clearValues[1].depthStencil = {1.0f, 0};
        renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
        renderPassInfo.pClearValues = clearValues.data();

        vkCmdBeginRenderPass(commandBuffer, &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

        VkViewport viewport{};
        viewport.x = 0.0f;
        viewport.y = 0.0f;
        viewport.width = static_cast<float>(grpSwapChain->getSwapChainExtent().width);
        viewport.height = static_cast<float>(grpSwapChain->getSwapChainExtent().height);
        viewport.minDepth = 0.0f;
        viewport.maxDepth = 1.0f;
        VkRect2D scissor{{0, 0}, grpSwapChain->getSwapChainExtent()};
        vkCmdSetViewport(commandBuffer, 0, 1, &viewport);
        vkCmdSetScissor(commandBuffer, 0, 1, &scissor);
    }

    void GrpRenderer::endSwapChainRenderPass(VkCommandBuffer commandBuffer) {
        assert(isFrameStarted && "Can't call endSwapChainRenderPass  while frame is not in progress");
        assert(commandBuffer == getCurrentCommandBuffer() &&
               "Can't end render pass on command buffer from a different frame");

        vkCmdEndRenderPass(commandBuffer);

    }
}