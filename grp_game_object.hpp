//
// Created by Piou on 06/11/2021.
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

#ifndef GRAPE_GRP_GAME_OBJECT_HPP
#define GRAPE_GRP_GAME_OBJECT_HPP

#include "grp_model.hpp"

// glm
#include <glm/gtc/matrix_transform.hpp>

// std
#include <memory>

namespace grp {

    struct TransformComponent {
        glm::vec3 translation{};  // (position offset)
        glm::vec3 scale{1.f, 1.f, 1.f};
        glm::vec3 rotation{};

        // Matrix corrsponds to Translate * Ry * Rx * Rz * Scale
        // Rotations correspond to Tait-bryan angles of Y(1), X(2), Z(3)
        // https://en.wikipedia.org/wiki/Euler_angles#Rotation_matrix
        glm::mat4 mat4() {
            const float c3 = glm::cos(rotation.z);
            const float s3 = glm::sin(rotation.z);
            const float c2 = glm::cos(rotation.x);
            const float s2 = glm::sin(rotation.x);
            const float c1 = glm::cos(rotation.y);
            const float s1 = glm::sin(rotation.y);
            return glm::mat4{
                {
                    scale.x * (c1 * c3 + s1 * s2 * s3),
                    scale.x * (c2 * s3),
                    scale.x * (c1 * s2 * s3 - c3 * s1), 0.0f,
                    },
                    {
                    scale.y * (c3 * s1 * s2 - c1 * s3),
                    scale.y * (c2 * c3),
                    scale.y * (c1 * c3 * s2 + s1 * s3), 0.0f,
                    },
                    {
                    scale.z * (c2 * s1),
                    scale.z * (-s2),
                    scale.z * (c1 * c2),
                    0.0f,
                    },
                    {
                        translation.x,
                        translation.y,
                        translation.z,
                        1.0f
                    }
            };
        }
    };

    class GrpGameObject {

    public:
        using id_t = unsigned int;

        static GrpGameObject createGameObject() {
            static id_t currentId = 0;
            return GrpGameObject{currentId++};
        }

        GrpGameObject(const GrpGameObject &) = delete;

        GrpGameObject &operator=(const GrpGameObject &) = delete;

        GrpGameObject(GrpGameObject &&) = default;

        GrpGameObject &operator=(GrpGameObject &&) = default;

        id_t getId() { return id; }

        std::shared_ptr<GrpModel> model{};
        glm::vec3 color{};
        TransformComponent transform{};

    private:
        GrpGameObject(id_t objId) : id{objId} {}

        id_t id;

    };

} // grp namespace


#endif //GRAPE_GRP_GAME_OBJECT_HPP
