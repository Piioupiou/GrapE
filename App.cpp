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
#include "simple_render_system.hpp"

// std
#include <array>
#include <stdexcept>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

namespace grp {

    App::App() {
        loadGameObjects();
    }

    App::~App() {
    }

    void App::run() {
        SimpleRenderSystem simpleRenderSystem(grpDevice, grpRenderer.getSwapChainRenderPass());

        while (!grpWindow.shouldClose()) {
            glfwPollEvents();

            if (auto commandBuffer = grpRenderer.beginFrame()) {
                grpRenderer.beginSwapChainRenderPass(commandBuffer);
                simpleRenderSystem.renderGameObjects(commandBuffer, gameObjects);
                grpRenderer.endSwapChainRenderPass(commandBuffer);
                grpRenderer.endFrame();
            }
        }

        vkDeviceWaitIdle(grpDevice.device());
    }

    void App::loadGameObjects() {
        std::vector<GrpModel::Vertex> vertices{{{0.0f,  -0.5f}, {1.0f, 0.0f, 0.0f}},
                                               {{0.5f,  0.5f},  {0.0f, 1.0f, 0.0f}},
                                               {{-0.5f, 0.5f},  {0.0f, 0.0f, 1.0f}}};

        auto grpModel = std::make_shared<GrpModel>(grpDevice, vertices);

        auto triangle = GrpGameObject::createGameObject();
        triangle.model = grpModel;
        triangle.color = {.1f, .8f, .1f};
        triangle.transform2d.translation.x = .2f;
        triangle.transform2d.scale = {2.f, .5f};
        triangle.transform2d.rotation = .25f * glm::two_pi<float>();

        gameObjects.push_back(std::move(triangle));
    }
}