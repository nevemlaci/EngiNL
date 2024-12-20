//
// Created by nevemlaci on 13/08/2024.
//

#pragma once
#include <memory>

#include "../export.hpp"
#include <SDL3/SDL.h>

namespace EngiNL{
    class Scene;
    namespace Component{
        struct NLExport SpriteRenderer{
            int id{};
            std::weak_ptr<SDL_Texture> texture;

            static void start_system(Scene* scene);

            static void update_system(Scene* scene);
        };
    }
}

