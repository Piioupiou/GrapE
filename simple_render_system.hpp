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

#ifndef GRAPE_SIMPLE_RENDER_SYSTEM_HPP
#define GRAPE_SIMPLE_RENDER_SYSTEM_HPP

#include "grp_pipeline.hpp"
#include "grp_device.hpp"
#include "grp_game_object.hpp"
#include "grp_camera.hpp"
#include "grp_frame_info.hpp"

// std
#include <memory>
#include <vector>

namespace grp {
    class SimpleRenderSystem {
    public:
        SimpleRenderSystem(GrpDevice &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);

        ~SimpleRenderSystem();

        SimpleRenderSystem(const SimpleRenderSystem &) = delete;

        SimpleRenderSystem &operator=(const SimpleRenderSystem &) = delete;

        void renderGameObjects(FrameInfo &frameInfo);

    private:
        GrpDevice &grpDevice;
        std::unique_ptr<GrpPipeline> grpPipeline;
        VkPipelineLayout pipelineLayout;

        void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);

        void createPipeline(VkRenderPass renderPass);
    };
} // grp namespace

#endif //GRAPE_SIMPLE_RENDER_SYSTEM_HPP
