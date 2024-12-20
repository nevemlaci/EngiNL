//
// Created by nevemlaci on 12/12/2024.
//

#include "iscript.hpp"
#include "src/Entity.hpp"

namespace EngiNL{
    Entity IScript::self() const {
        return Entity(m_entity, m_scene);
    }
}
