//
// Created by nevemlaci on 11/12/2024.
//

#include "sprite_renderer.hpp"

#include "transform.hpp"
#include "src/Scene.hpp"
#include "src/Engine.hpp"

namespace EngiNL::Component{
        void SpriteRenderer::start_system(Scene* scene){

        }

        void SpriteRenderer::update_system(Scene* scene){
            std::size_t rendered_count = 0;
            auto entities = scene->GetRegistry().view<Component::Transform, Component::SpriteRenderer>();
            SDL_RenderClear(scene->GetEngine().GetRenderer());
            for(auto& entity : entities) {
                auto pos = scene->GetRegistry().get<Component::Transform>(entity);
                if(pos.inside(scene->GetEngine().GetDimensions())) {
                    auto renderer_component = scene->GetRegistry().get<Component::SpriteRenderer>(entity);
                    const auto pos_rect = static_cast<const SDL_FRect>(pos);

                    SDL_RenderTexture(
                        scene->GetEngine().GetRenderer(),
                        renderer_component.texture.lock().get(),
                        nullptr,
                        &pos_rect
                        );
                    ++rendered_count;
                }
            }
            SDL_RenderPresent(scene->GetEngine().GetRenderer());
         }
}
