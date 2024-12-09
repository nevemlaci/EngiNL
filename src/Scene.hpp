//
// Created by nevemlaci on 10/08/2024.
//

#pragma once
#include "entt_include.hpp"
#include "export.hpp"

namespace EngiNL{
    class NLExport Engine;
    class NLExport Entity;

    class NLExport Scene{
        entt::registry m_registry;
        Engine* m_engine = nullptr;
    public:
        explicit Scene(Engine* engine);
        entt::registry& GetRegistry() {
            return m_registry;
        }

        [[nodiscard]] Engine& GetEngine() const {
            return *m_engine;
        }

        Entity AddEntity();
        std::vector<Entity> AddEntity(entt::registry::size_type amount);
        void DeleteEntity(Entity entity);


        void Update();
    };
}
