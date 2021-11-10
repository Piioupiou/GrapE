//
// Created by Piou on 08/11/2021.
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

#ifndef GRAPE_GRP_CAMERA_HPP
#define GRAPE_GRP_CAMERA_HPP

// GLM
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

namespace grp {
    class GrpCamera {
    public:
        void setOrthographicProjection(float left, float right, float top, float bottom, float near, float far);
        void setPerspectiveProjection(float fovy, float aspect, float near, float far);

        void setViewDirection(glm::vec3 position, glm::vec3 direction, glm::vec3 up = glm::vec3(0.f, -1.f, 0.f));
        void setViewTarget(glm::vec3 position, glm::vec3 target, glm::vec3 up = glm::vec3(0.f, -1.f, 0.f));
        void setViewYXZ(glm::vec3 position, glm::vec3 rotation);


        const glm::mat4& getProjection() const { return projectionMatrix; }
        const glm::mat4& getView() const { return viewMatrix; }

    private:
        glm::mat4 projectionMatrix{1.f};
        glm::mat4 viewMatrix{1.f};

    };
} // grp namespace


#endif //GRAPE_GRP_CAMERA_HPP
