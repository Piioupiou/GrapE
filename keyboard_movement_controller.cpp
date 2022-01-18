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

#include "keyboard_movement_controller.hpp"

namespace grp {

    float KeyboardMovementController::lastY = App::WIDTH/2.f;
    float KeyboardMovementController::lastX = App::HEIGHT/2.f;
    float KeyboardMovementController::yaw = 0;
    float KeyboardMovementController::pitch = 0;
    bool KeyboardMovementController::firstmouse = true;

    void KeyboardMovementController::moveInPlaneXZ(GLFWwindow *window, float dt, grp::GrpGameObject &gameObject) {

        double xpos, ypos;

        if(glfwGetKey(window, keys.exit) == GLFW_PRESS) exit(1);

        glm::vec3 rotate{0};

        rotate.y += pitch;
        rotate.x -= yaw;


        if(glm::dot(rotate, rotate) > glm::epsilon<float>())
            gameObject.transform.rotation += lookSpeed * dt * glm::normalize(rotate);

        // limit pitch values between +/- 85x degrees
        gameObject.transform.rotation.x = glm::clamp(gameObject.transform.rotation.x, -1.5f, 1.5f);
        gameObject.transform.rotation.y = glm::mod(gameObject.transform.rotation.y, glm::two_pi<float>());

        float yaw1 = gameObject.transform.rotation.y;
        const glm::vec3 forwardDir{sin(yaw1), -gameObject.transform.rotation.x, cos(yaw1)};
        const glm::vec3 rightDir{forwardDir.z, 0.f, -forwardDir.x};
        const glm::vec3 upDir{ 0.f, -1.f, 0.f};

        glm::vec3 moveDir{0.f };

        if(glfwGetKey(window, keys.moveForward) == GLFW_PRESS) moveDir += forwardDir;
        if(glfwGetKey(window, keys.moveBackward) == GLFW_PRESS) moveDir -= forwardDir;
        if(glfwGetKey(window, keys.moveRight) == GLFW_PRESS) moveDir += rightDir;
        if(glfwGetKey(window, keys.moveLeft) == GLFW_PRESS) moveDir -= rightDir;
        if(glfwGetKey(window, keys.moveUp) == GLFW_PRESS) moveDir += upDir;
        if(glfwGetKey(window, keys.moveDown) == GLFW_PRESS) moveDir -= upDir;

        if(glm::dot(moveDir, moveDir) > glm::epsilon<float>())
            gameObject.transform.translation += moveSpeed * dt * glm::normalize(moveDir);

        yaw = 0;
        pitch = 0;
    }

    void KeyboardMovementController::mouse_callback(GLFWwindow* window, double xpos, double ypos)
    {
        if (firstmouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstmouse = false;
        }
        float xoffset = xpos - lastX;
        float yoffset = ypos - lastY;
        lastY = ypos;
        lastX = xpos;

        float sensitivity = 100.f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        pitch += xoffset;
        yaw += yoffset;

//        if(pitch > 89.0f)
//            pitch = 89.0f;
//        if(pitch < -89.0f)
//            pitch = -89.0f;
    }
} // grp namespace
