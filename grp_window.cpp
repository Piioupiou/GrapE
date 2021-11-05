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

#include "grp_window.hpp"

//std
#include <stdexcept>

namespace grp {

    GrpWindow::GrpWindow(int w, int h, std::string windowName) : width(w), height(h), windowName(windowName) {
        initWindow();
    }

    GrpWindow::~GrpWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void GrpWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
    }

    void GrpWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if(glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
            throw std::runtime_error("Failed to create window surface");

    }

    void GrpWindow::framebufferResizeCallback(GLFWwindow *window, int width, int height) {
        auto grpWindow = reinterpret_cast<GrpWindow *>(glfwGetWindowUserPointer(window));
        grpWindow->framebufferResized = true;
        grpWindow->width = width;
        grpWindow->height = height;
    }

} // grp namespace
