//
// Created by nevemlaci on 13/08/2024.
//

#pragma once
#include "export.hpp"

#define e_nodiscard [[nodiscard("Method returning non-void should not be discarded")]]

#include <entt/entt.hpp>

#include "Scene.hpp"
#include "Component/custom_script.hpp"

namespace EngiNL{

    class NLExport Entity{
        entt::entity m_entity;
        Scene* m_scene;

    public:
        Entity(entt::entity entity, Scene* scene);

        explicit Entity(Scene* scene);

        e_nodiscard
        entt::entity Get() const { return m_entity; }

        template<typename... Components>
        void AddComponents(Components&&... components) {
            (AddComponent(std::forward<Components>(components)), ...);
        }

        template<typename Component>
        requires (!std::derived_from<Component, IScript>)
        void AddComponent(Component&& component) {
            m_scene->GetRegistry().emplace_or_replace<Component>(m_entity, component);
        }

        template<typename Script>
        requires std::derived_from<Script, IScript>
        void EngiNL::Entity::AddComponent() {
            auto script_ptr = std::make_unique<Script>(m_entity, m_scene);
            Component::CustomScript script = {std::move(script_ptr)};
            m_scene->GetRegistry().emplace_or_replace<Script>(m_entity, script);
        }

        template<typename Component>
        e_nodiscard
        bool HasComponent() const {
            return m_scene->GetRegistry().all_of<Component>(m_entity);
        }

        template<typename Component>
        Component* GetComponent() {
            return m_scene->GetRegistry().try_get<Component>(m_entity);
        }

        template<typename Component>
        void RemoveComponent() const {
            m_scene->GetRegistry().remove<Component>(m_entity);
        }
    };
}
