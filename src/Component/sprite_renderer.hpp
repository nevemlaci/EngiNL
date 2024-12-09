//
// Created by nevemlaci on 13/08/2024.
//

#pragma once
#include "../export.hpp"
#include <SDL3/SDL.h>

namespace EngiNL::Component{
    struct NLExport SpriteRenderer{
        int id{};
        std::weak_ptr<SDL_Texture> texture;
    };
}