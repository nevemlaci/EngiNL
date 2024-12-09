//
// Created by nevemlaci on 09/12/2024.
//
#include "custom_script_system.hpp"

#include "../Component/sprite_renderer.hpp"
#include "../Component/transform.hpp"
#include "../Scene.hpp"

namespace EngiNL{
    int CustomScriptUpdateSystem(EngiNL::Scene* scene) {
        auto entities = scene->GetRegistry().view<Component::Transform, Component::CustomScript>();

        return 0;
    }
}
