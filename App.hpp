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

#ifndef GRAPE_APP_HPP
#define GRAPE_APP_HPP

#include "grp_window.hpp"
#include "grp_pipeline.hpp"
#include "grp_device.hpp"
#include "grp_swap_chain.hpp"
#include "grp_model.hpp"

// std
#include <memory>
#include <vector>

namespace grp {
    class App {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;
        App();
        ~App();

        App(const App &) = delete;
        App &operator=(const App &) = delete;

        void run();

    private:
        GrpWindow grpWindow{WIDTH, HEIGHT, "Grape Example"};
        GrpDevice grpDevice{grpWindow};
        std::unique_ptr<GrpSwapChain> grpSwapChain;
        std::unique_ptr<GrpPipeline> grpPipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
        std::unique_ptr<GrpModel> grpModel;

        void loadModels();

        void createPipelineLayout();

        void createPipeline();

        void createCommandBuffers();

        void freeCommandBuffers();

        void drawFrame();

        void recreateSwapChain();

        void recordCommandBuffer(int imageIndex);
    };
} // grp namespace


#endif //GRAPE_APP_HPP
