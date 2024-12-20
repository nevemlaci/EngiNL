//
// Created by nevemlaci on 11/12/2024.
//

#include "custom_script_holder.hpp"

#include "transform.hpp"
#include "src/Scene.hpp"
#include "src/Engine.hpp"
#include "src/Interface/iscript.hpp"

namespace EngiNL{
    void ScriptHolder::start_system(Scene* scene) {
        auto& registry = scene->GetRegistry();
        auto entities = registry.view<Component::Transform, ScriptHolder>();

        for(auto& entity : entities) {
            auto& scripts = scene->GetRegistry().get<ScriptHolder>(entity);
            for (auto& script : scripts.m_scripts) {
                script->start();
            }
        }
    }

    void ScriptHolder::update_system(Scene* scene) {
        auto& registry = scene->GetRegistry();
        auto entities = registry.view<Component::Transform, ScriptHolder>();

        for(auto& entity : entities) {
            auto& scripts = scene->GetRegistry().get<ScriptHolder>(entity);
            for (auto& script : scripts.m_scripts) {
                script->update();
            }
        }

    }
}
