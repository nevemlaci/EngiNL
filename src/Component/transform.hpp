//
// Created by nevemlaci on 13/08/2024.
//

#pragma once
#include "../Maths/Vector2.hpp"
#include <SDL3/SDL.h>
#include "../export.hpp"

namespace EngiNL::Component{
    struct NLExport Transform{
        Math::Vector2 position;
        Math::Vector2 scale;
        double rotation{};

        operator SDL_FRect() const{
            return {position.x, position.y, scale.x, scale.y};
        }
    };
}