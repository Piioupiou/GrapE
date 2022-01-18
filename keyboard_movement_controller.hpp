//
// Created by Piou on 10/11/2021.
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

#ifndef GRAPE_KEYBOARD_MOVEMENT_CONTROLLER_HPP
#define GRAPE_KEYBOARD_MOVEMENT_CONTROLLER_HPP

#include "App.hpp"
#include "grp_game_object.hpp"
#include "grp_window.hpp"

namespace grp {

    class KeyboardMovementController {

    public:
        struct KeyMappings {
            int moveLeft = GLFW_KEY_A;
            int moveRight = GLFW_KEY_D;
            int moveForward = GLFW_KEY_W;
            int moveBackward = GLFW_KEY_S;
            int moveUp = GLFW_KEY_E;
            int moveDown = GLFW_KEY_Q;
            int exit = GLFW_KEY_ESCAPE;
        };

        void moveInPlaneXZ(GLFWwindow *window, float dt, GrpGameObject &gameObject);
        static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

        KeyMappings keys{};
        float moveSpeed{3.f};
        float lookSpeed{10.f};
        static float lastX;
        static float lastY;
        static float yaw, pitch;
        static bool firstmouse;
    };
} // grp namespace


#endif //GRAPE_KEYBOARD_MOVEMENT_CONTROLLER_HPP
