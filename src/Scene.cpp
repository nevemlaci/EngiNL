//
// Created by nevemlaci on 10/08/2024.
//

#include "Scene.hpp"
#include "Entity.hpp"
#include <entt/entt.hpp>
#include <SDL3/SDL.h>

#include "Engine.hpp"
#include "System/sprite_renderer_system.hpp"


EngiNL::Scene::Scene(Engine* engine) : m_engine(engine) {

}

EngiNL::Entity EngiNL::Scene::AddEntity() {
    const entt::entity entity = m_registry.create();
    return Entity(entity, this);
}

std::vector<EngiNL::Entity> EngiNL::Scene::AddEntity(entt::registry::size_type amount) {
    assert(amount > 1 && "Only use this function to add more than 1 entity.");
    std::vector<Entity> ret;
    for(auto i = amount; i > 0; --i) {
        const entt::entity entity = m_registry.create();
        ret.emplace_back(entity, this);
    }
    return ret;

}
void EngiNL::Scene::DeleteEntity(EngiNL::Entity entity) {
    m_registry.destroy(entity.Get());
}

void EngiNL::Scene::Update() {
    SDL_Event event;
    while (true) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                default:
                    break;
                case SDL_EVENT_QUIT:
                    return;
            }
        }
        SpriteRendererSystem(this);

    }
}
