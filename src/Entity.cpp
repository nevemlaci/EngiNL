//
// Created by nevemlaci on 13/08/2024.
//

#include "Entity.hpp"

EngiNL::Entity::Entity(entt::entity entity, EngiNL::Scene* scene) : m_entity(entity), m_scene(scene) {}

EngiNL::Entity::Entity(EngiNL::Scene* scene) : m_entity(scene->GetRegistry().create()), m_scene(scene) {}


