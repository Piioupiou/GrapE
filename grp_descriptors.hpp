//
// Created by Piou on 09/12/2021.
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

#ifndef GRAPE_GRP_DESCRIPTORS_HPP
#define GRAPE_GRP_DESCRIPTORS_HPP

#include "grp_device.hpp"


// std
#include <memory>
#include <unordered_map>
#include <vector>

namespace grp {

    class GrpDescriptorSetLayout {
    public:
        class Builder {
        public:
            Builder(GrpDevice &grpDevice) : grpDevice{grpDevice} {}

            Builder &addBinding(
                    uint32_t binding,
                    VkDescriptorType descriptorType,
                    VkShaderStageFlags stageFlags,
                    uint32_t count = 1);
            std::unique_ptr<GrpDescriptorSetLayout> build() const;

        private:
            GrpDevice &grpDevice;
            std::unordered_map<uint32_t, VkDescriptorSetLayoutBinding> bindings{};
        };

        GrpDescriptorSetLayout(
                GrpDevice &grpDevice, std::unordered_map<uint32_t, VkDescriptorSetLayoutBinding> bindings);
        ~GrpDescriptorSetLayout();
        GrpDescriptorSetLayout(const GrpDescriptorSetLayout &) = delete;
        GrpDescriptorSetLayout &operator=(const GrpDescriptorSetLayout &) = delete;

        VkDescriptorSetLayout getDescriptorSetLayout() const { return descriptorSetLayout; }

    private:
        GrpDevice &grpDevice;
        VkDescriptorSetLayout descriptorSetLayout;
        std::unordered_map<uint32_t, VkDescriptorSetLayoutBinding> bindings;

        friend class GrpDescriptorWriter;
    };

    class GrpDescriptorPool {
    public:
        class Builder {
        public:
            Builder(GrpDevice &grpDevice) : grpDevice{grpDevice} {}

            Builder &addPoolSize(VkDescriptorType descriptorType, uint32_t count);
            Builder &setPoolFlags(VkDescriptorPoolCreateFlags flags);
            Builder &setMaxSets(uint32_t count);
            std::unique_ptr<GrpDescriptorPool> build() const;

        private:
            GrpDevice &grpDevice;
            std::vector<VkDescriptorPoolSize> poolSizes{};
            uint32_t maxSets = 1000;
            VkDescriptorPoolCreateFlags poolFlags = 0;
        };

        GrpDescriptorPool(
                GrpDevice &grpDevice,
                uint32_t maxSets,
                VkDescriptorPoolCreateFlags poolFlags,
                const std::vector<VkDescriptorPoolSize> &poolSizes);
        ~GrpDescriptorPool();
        GrpDescriptorPool(const GrpDescriptorPool &) = delete;
        GrpDescriptorPool &operator=(const GrpDescriptorPool &) = delete;

        bool allocateDescriptor(
                const VkDescriptorSetLayout descriptorSetLayout, VkDescriptorSet &descriptor) const;

        void freeDescriptors(std::vector<VkDescriptorSet> &descriptors) const;

        void resetPool();

    private:
        GrpDevice &grpDevice;
        VkDescriptorPool descriptorPool;

        friend class GrpDescriptorWriter;
    };

    class GrpDescriptorWriter {
    public:
        GrpDescriptorWriter(GrpDescriptorSetLayout &setLayout, GrpDescriptorPool &pool);

        GrpDescriptorWriter &writeBuffer(uint32_t binding, VkDescriptorBufferInfo *bufferInfo);
        GrpDescriptorWriter &writeImage(uint32_t binding, VkDescriptorImageInfo *imageInfo);

        bool build(VkDescriptorSet &set);
        void overwrite(VkDescriptorSet &set);

    private:
        GrpDescriptorSetLayout &setLayout;
        GrpDescriptorPool &pool;
        std::vector<VkWriteDescriptorSet> writes;
    };

}  // namespace grp

#endif //GRAPE_GRP_DESCRIPTORS_HPP
