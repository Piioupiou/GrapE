//
// Created by Piou on 04/11/2021.
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

#ifndef GRAPE_GRP_MODEL_HPP
#define GRAPE_GRP_MODEL_HPP

#include "grp_device.hpp"

// GLM
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

// std
#include <vector>

namespace grp {
    class GrpModel {
    public:
        struct Vertex {
            glm::vec3 position;
            glm::vec3 color;

            static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
            static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
        };

        GrpModel(GrpDevice &device, const std::vector<Vertex> &vertices);
        ~GrpModel();

        GrpModel(const GrpModel &) = delete;
        GrpModel &operator=(const GrpModel &) = delete;

        void bind(VkCommandBuffer commandBuffer);
        void draw(VkCommandBuffer commandBuffer);

    private:
        void createVertexBuffers(const std::vector<Vertex> &vertices);

        GrpDevice &grpDevice;
        VkBuffer vertexBuffer;
        VkDeviceMemory vertexBufferMemory;
        uint32_t vertexCount;

    };
} // grp namespace


#endif //GRAPE_GRP_MODEL_HPP
