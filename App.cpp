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
#include "keyboard_movement_controller.hpp"
#include "grp_camera.hpp"
#include "simple_render_system.hpp"
#include "grp_buffer.hpp"

// std
#include <array>
#include <chrono>
#include <stdexcept>
#include <cassert>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

namespace grp {

    struct GlobalUbo {
        glm::mat4 projectionView{1.f};
        glm::vec4 ambientLightColor{1.f, 1.f, 1.f, .02f};  // w is intensity
        glm::vec3 lightPosition{-1.f};
        alignas(16) glm::vec4 lightColor{1.f};  // w is light intensity
    };

    App::App() {
        globalPool = GrpDescriptorPool::Builder(grpDevice)
                .setMaxSets(GrpSwapChain::MAX_FRAMES_IN_FLIGHT)
                .addPoolSize(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, GrpSwapChain::MAX_FRAMES_IN_FLIGHT)
                .build();
        loadGameObjects();
    }

    App::~App() {
    }

    void App::run() {
        std::vector<std::unique_ptr<GrpBuffer>> uboBuffers(GrpSwapChain::MAX_FRAMES_IN_FLIGHT);
        for (int i = 0; i < uboBuffers.size(); i++) {
            uboBuffers[i] = std::make_unique<GrpBuffer>(
                    grpDevice,
                    sizeof(GlobalUbo),
                    1,
                    VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
                    VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);
            uboBuffers[i]->map();
        }

        auto globalSetLayout = GrpDescriptorSetLayout::Builder(grpDevice)
                .addBinding(0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_SHADER_STAGE_ALL_GRAPHICS)
                .build();

        std::vector<VkDescriptorSet> globalDescriptorSets(GrpSwapChain::MAX_FRAMES_IN_FLIGHT);
        for (int i = 0; i < globalDescriptorSets.size(); i++) {
            auto bufferInfo = uboBuffers[i]->descriptorInfo();
            GrpDescriptorWriter(*globalSetLayout, *globalPool)
            .writeBuffer(0, &bufferInfo)
            .build(globalDescriptorSets[i]);
        }

        SimpleRenderSystem simpleRenderSystem(grpDevice, grpRenderer.getSwapChainRenderPass(), globalSetLayout->getDescriptorSetLayout());
        GrpCamera camera{};
        camera.setViewTarget(glm::vec3(-1.f, -2.f, 2.f), glm::vec3(0.f, 0.f, 2.5f));

        auto viewerObject = GrpGameObject::createGameObject();
        viewerObject.transform.translation.z = -2.5f;

        auto currentTime = std::chrono::high_resolution_clock::now();
        KeyboardMovementController cameraController{};

        glfwSetInputMode(grpWindow.getGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        GLFWcursorposfun fun = cameraController.mouse_callback;
        glfwSetCursorPosCallback(grpWindow.getGLFWwindow(),fun);

        while (!grpWindow.shouldClose()) {
            glfwPollEvents();

            auto newTime = std::chrono::high_resolution_clock::now();
            float frameTime = std::chrono::duration<float, std::chrono::seconds::period>(newTime - currentTime).count();
            currentTime = newTime;

            cameraController.moveInPlaneXZ(grpWindow.getGLFWwindow(), frameTime, viewerObject);
            camera.setViewYXZ(viewerObject.transform.translation, viewerObject.transform.rotation);

            float aspect = grpRenderer.getAspectRatio();
            camera.setPerspectiveProjection(glm::radians(50.f), aspect, 0.1f, 100.f);

            if (auto commandBuffer = grpRenderer.beginFrame()) {
                int frameIndex = grpRenderer.getFrameIndex();
                FrameInfo frameInfo{
                    frameIndex,
                    frameTime,
                    commandBuffer,
                    camera,
                    globalDescriptorSets[frameIndex],
                    gameObjects
                };

                // update
                GlobalUbo ubo{};
                ubo.projectionView = camera.getProjection() * camera.getView();
                uboBuffers[frameIndex]->writeToBuffer(&ubo);
                uboBuffers[frameIndex]->flush();

                // render
                grpRenderer.beginSwapChainRenderPass(commandBuffer);
                simpleRenderSystem.renderGameObjects(frameInfo);
                grpRenderer.endSwapChainRenderPass(commandBuffer);
                grpRenderer.endFrame();
            }
        }

        vkDeviceWaitIdle(grpDevice.device());
    }

    void App::loadGameObjects() {
        std::shared_ptr<GrpModel> grpModel = GrpModel::createModelFromFile(grpDevice, R"(C:\Users\pierr\CLionProjects\GrapE\models\smooth_vase.obj)");

        auto smoothVase = GrpGameObject::createGameObject();
        smoothVase.model = grpModel;
        smoothVase.transform.translation = {-.5f, .5f, 0.f};
        smoothVase.transform.scale = glm::vec3(3.f);
        gameObjects.emplace(smoothVase.getId(), std::move(smoothVase));

        grpModel = GrpModel::createModelFromFile(grpDevice, R"(C:\Users\pierr\CLionProjects\GrapE\models\flat_vase.obj)");

        auto flatVase = GrpGameObject::createGameObject();
        flatVase.model = grpModel;
        flatVase.transform.translation = {.5f, .5f, 0.f};
        flatVase.transform.scale = glm::vec3(3.f);
        gameObjects.emplace(flatVase.getId(), std::move(flatVase));

        grpModel = GrpModel::createModelFromFile(grpDevice, R"(C:\Users\pierr\CLionProjects\GrapE\models\quad.obj)");
        auto floor = GrpGameObject::createGameObject();
        floor.model = grpModel;
        floor.transform.translation = {0.f, .5f, 0.f};
        floor.transform.scale = {3.f, 1.f, 3.f};
        gameObjects.emplace(floor.getId(), std::move(floor));
    }
}