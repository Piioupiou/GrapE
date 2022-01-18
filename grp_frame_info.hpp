//
// Created by Piou on 28/11/2021.
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

#ifndef GRAPE_GRP_FRAME_INFO_HPP
#define GRAPE_GRP_FRAME_INFO_HPP

#include "grp_camera.hpp"
#include "grp_game_object.hpp"

//lib
#include <vulkan/vulkan.h>

namespace grp {

    struct FrameInfo {
        int frameIndex;
        float frameTime;
        VkCommandBuffer commandBuffer;
        GrpCamera &camera;
        VkDescriptorSet globalDescriptor;
        GrpGameObject::Map &gameObjects;
    };

} // grp namespace

#endif //GRAPE_GRP_FRAME_INFO_HPP
