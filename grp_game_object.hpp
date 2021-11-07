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

// std
#include <memory>

namespace grp {

    struct Transform2dComponent {
        glm::vec2 translation{};  // (position offset)
        glm::vec2 scale{1.f, 1.f};
        float rotation;

        glm::mat2 mat2() {
            const float s = glm::sin(rotation);
            const float c = glm::cos(rotation);
            glm::mat2 rotMatrix{{c, s}, {-s, c}};

            glm::mat2 scaleMat{{scale.x, .0f}, {.0f, scale.y}};
            return rotMatrix * scaleMat;
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
        Transform2dComponent transform2d{};

    private:
        GrpGameObject(id_t objId) : id{objId} {}

        id_t id;

    };

} // grp namespace


#endif //GRAPE_GRP_GAME_OBJECT_HPP
