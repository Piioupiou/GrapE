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
#include "grp_device.hpp"
#include "grp_game_object.hpp"
#include "grp_renderer.hpp"
#include "grp_descriptors.hpp"

// std
#include <memory>
#include <vector>

namespace grp {
    class App {
    public:
        static constexpr int WIDTH = 1920;
        static constexpr int HEIGHT = 1080;
        App();
        ~App();

        App(const App &) = delete;
        App &operator=(const App &) = delete;

        void run();

    private:
        GrpWindow grpWindow{WIDTH, HEIGHT, "Grape Example"};
        GrpDevice grpDevice{grpWindow};
        GrpRenderer grpRenderer{grpWindow, grpDevice};

        // Careful here, declarations order matters ! (Pool need to be destroy before device)
        std::unique_ptr<GrpDescriptorPool> globalPool{};
        GrpGameObject::Map gameObjects;

        void loadGameObjects();
    };
} // grp namespace


#endif //GRAPE_APP_HPP
