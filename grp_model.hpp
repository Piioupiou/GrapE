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
#include "grp_buffer.hpp"

// GLM
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/glm.hpp>

// std
#include <memory>
#include <vector>

namespace grp {
    class GrpModel {
    public:
        struct Vertex {
            glm::vec3 position{};
            glm::vec3 color{};
            glm::vec3 normal{};
            glm::vec2 uv{};


            static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
            static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();

            bool operator ==(const Vertex &other) const {
                return position == other.position && color == other.color && normal == other.normal && uv == other.uv;
            }
        };

        struct Builder {
            std::vector<Vertex> vertices{};
            std::vector<uint32_t> indices{};

            void load(const std::string & filepath);
        };

        GrpModel(GrpDevice &device, const GrpModel::Builder &builder);
        ~GrpModel();

        GrpModel(const GrpModel &) = delete;
        GrpModel &operator=(const GrpModel &) = delete;

        static std::unique_ptr<GrpModel> createModelFromFile(GrpDevice &device, const std::string &filepath);

        void bind(VkCommandBuffer commandBuffer);
        void draw(VkCommandBuffer commandBuffer);

    private:
        void createVertexBuffers(const std::vector<Vertex> &vertices);
        void createIndexBuffers(const std::vector<uint32_t> &indices);

        GrpDevice &grpDevice;
        std::unique_ptr<GrpBuffer> vertexBuffer;
        uint32_t vertexCount;

        bool hasIndexBuffer = false;
        std::unique_ptr<GrpBuffer> indexBuffer;
        uint32_t indexCount;
    };
} // grp namespace


#endif //GRAPE_GRP_MODEL_HPP
