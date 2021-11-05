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

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_MESSAGES
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include "App.hpp"
//std
#include <iostream>
#include <cstdlib>
#include <stdexcept>

int main() {
    grp::App app{};

    try {
        app.run();
    } catch (const  std::exception &e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}