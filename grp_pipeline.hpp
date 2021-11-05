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

#ifndef GRAPE_GRP_PIPELINE_HPP
#define GRAPE_GRP_PIPELINE_HPP

#include "grp_device.hpp"

#include <string>
#include <vector>

namespace grp {

    struct PipelineConfigInfo {
        PipelineConfigInfo(const PipelineConfigInfo &) = delete;
        PipelineConfigInfo &operator=(const PipelineConfigInfo &) = delete;

        VkPipelineViewportStateCreateInfo viewportInfo;
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        std::vector<VkDynamicState> dynamicStateEnables;
        VkPipelineDynamicStateCreateInfo dynamicStateInfo;
        VkPipelineLayout pipelineLayout = nullptr;
        VkRenderPass renderPass = nullptr;
        uint32_t subpass = 0;
    };

    class GrpPipeline {
    public:
        GrpPipeline() = default;

        GrpPipeline(GrpDevice &device,
                    const std::string &vertFilepath,
                    const std::string &fragFilePath,
                    const PipelineConfigInfo &configInfo);

        ~GrpPipeline();

        GrpPipeline(const GrpPipeline &) = delete;

        GrpPipeline& operator=(const GrpPipeline &) = delete;

        static void defaultPipelineConfigInfo(PipelineConfigInfo &configInfo);

        void bind(VkCommandBuffer commandBuffer);
    private:
        static std::vector<char> readFile(const std::string &filepath);

        void createGraphicsPipeline(const std::string &vertFilePath,
                                           const std::string &fragFilePath,
                                           const PipelineConfigInfo &configInfo);

        void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);

        GrpDevice &grpDevice;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
} // grp namespace

#endif //GRAPE_GRP_PIPELINE_HPP
