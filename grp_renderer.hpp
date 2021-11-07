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

#ifndef GRAPE_GRP_RENDERER_HPP
#define GRAPE_GRP_RENDERER_HPP

#include "grp_device.hpp"
#include "grp_swap_chain.hpp"
#include "grp_window.hpp"

// std
#include <memory>
#include <vector>
#include <cassert>

namespace grp {
    class GrpRenderer {

    public:
        GrpRenderer(GrpWindow &window, GrpDevice &device);
        ~GrpRenderer();

        GrpRenderer(const GrpRenderer &) = delete;
        GrpRenderer &operator=(const GrpRenderer &) = delete;

        VkRenderPass getSwapChainRenderPass() const { return grpSwapChain->getRenderPass(); }

        bool isFrameInProgress() const { return isFrameStarted; }

        VkCommandBuffer getCurrentCommandBuffer() const {
            assert(isFrameStarted && "Cannot get command buffer when frame is not in progress" );
            return commandBuffers[currentFrameIndex];
        }

        bool getFrameIndex() const {
            assert(isFrameStarted && "Cannot get frame index when frame is not in progress" );
            return currentFrameIndex;
        }

        VkCommandBuffer beginFrame();
        void endFrame();

        void beginSwapChainRenderPass(VkCommandBuffer commandBuffer);
        void endSwapChainRenderPass(VkCommandBuffer commandBuffer);


    private:
        GrpWindow &grpWindow;
        GrpDevice &grpDevice;
        std::unique_ptr<GrpSwapChain> grpSwapChain;
        std::vector<VkCommandBuffer> commandBuffers;
        uint32_t currentImageIndex;
        int currentFrameIndex{0};
        bool isFrameStarted{false};

        void createCommandBuffers();
        void freeCommandBuffers();
        void recreateSwapChain();
    };
} // grp namespace


#endif //GRAPE_GRP_RENDERER_HPP
