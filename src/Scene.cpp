//
// Created by nevemlaci on 10/08/2024.
//

#include "Scene.hpp"
#include "Entity.hpp"
#include <entt/entt.hpp>
#include <thread>
#include <SDL3/SDL.h>

#include "Engine.hpp"
#include "Component/custom_script_holder.hpp"
#include "Component/sprite_renderer.hpp"
#include "Component/transform.hpp"


EngiNL::Scene::Scene(Engine* engine) :
m_engine(engine), m_time(std::chrono::high_resolution_clock::now())
{

}

EngiNL::Entity EngiNL::Scene::AddEntity() {
    const entt::entity entity = m_registry.create();
    Entity e(entity, this);
    e.AddComponent<Component::Transform>({Math::Vector2{0,0},Math::Vector2{0, 0}});
    ScriptHolder holder;
    e.AddComponent<ScriptHolder>(std::move(holder));
    return e;
}

std::vector<EngiNL::Entity> EngiNL::Scene::AddEntity(entt::registry::size_type amount) {
    assert(amount > 1 && "Only use this function to add more than 1 entity.");
    std::vector<Entity> ret;
    for(auto i = amount; i > 0; --i) {
        auto entity = AddEntity();
        ret.emplace_back(entity);
    }
    return ret;

}
void EngiNL::Scene::DeleteEntity(EngiNL::Entity entity) {
    m_registry.destroy(entity.Get());
}

void EngiNL::Scene::Run() {
    Component::SpriteRenderer::start_system(this);
    ScriptHolder::start_system(this);
    Update();
}

void EngiNL::Scene::Update() {
    using clock = std::chrono::high_resolution_clock ;
    int sleep_time = 1000000.0 / GetEngine().GetTargetFps();
    SDL_Event event;
    while (true) {
        auto frame_start = clock::now();
        m_delta_time = std::chrono::duration_cast<std::chrono::microseconds>(clock::now() - m_time);
        m_time = clock::now();
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                default:
                    break;
                case SDL_EVENT_QUIT:
                    return;
            }
        }
        ScriptHolder::update_system(this);
        Component::SpriteRenderer::update_system(this);


        if(GetEngine().GetTargetFps() > 0) {
            auto frame_end = clock::now();
            while (std::chrono::duration_cast<std::chrono::microseconds>(frame_end - frame_start) < std::chrono::microseconds(sleep_time)) {
                frame_end = clock::now();
            }
        }
    }
}
