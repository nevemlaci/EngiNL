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

        [[nodiscard]] bool inside(SDL_FRect rect) const {
            SDL_FRect this_rect = *this;
            return SDL_HasRectIntersectionFloat(&this_rect, &rect);
        }

        static void start_system();
        static void update_system();
    };
}