//
// Created by nevemlaci on 09/12/2024.
//

#include "../Entity.hpp"
#include "IScript.hpp"

namespace EngiNL{
    Entity IScript::self() const {
        return Entity(m_self, m_scene);
    }

    IScript::IScript(entt::entity self, Scene* scene) : m_self(self), m_scene(scene) {

    }
}
