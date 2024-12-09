//
// Created by nevemlaci on 05/09/2024.
//

#include "sprite_renderer_system.hpp"

#include "../Engine.hpp"
#include "../Scene.hpp"
#include "../Component/sprite_renderer.hpp"
#include "../Component/transform.hpp"

int EngiNL::SpriteRendererSystem(EngiNL::Scene* scene) {
    auto entities = scene->GetRegistry().view<Component::Transform, Component::SpriteRenderer>();
    SDL_RenderClear(scene->GetEngine().GetRenderer());
    for(auto& entity : entities) {
        auto pos = scene->GetRegistry().get<Component::Transform>(entity);
        auto renderer_component = scene->GetRegistry().get<Component::SpriteRenderer>(entity);
        const auto pos_rect = static_cast<const SDL_FRect>(pos);
        SDL_RenderTexture(
            scene->GetEngine().GetRenderer(),
            renderer_component.texture.lock().get(),
            nullptr,
            &pos_rect
            );
    }
    return SDL_RenderPresent(scene->GetEngine().GetRenderer());
}
