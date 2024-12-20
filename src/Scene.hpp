//
// Created by nevemlaci on 10/08/2024.
//

#pragma once
#include <chrono>
#include "entt_include.hpp"
#include "export.hpp"

namespace EngiNL{
    class NLExport Engine;
    class NLExport Entity;

    class NLExport Scene{
        entt::registry m_registry;
        Engine* m_engine = nullptr;
        bool is_active = false;
        std::chrono::steady_clock::time_point m_time;
        std::chrono::microseconds m_delta_time;
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

        void Run();
        void Update();

        [[nodiscard]] auto DeltaTime() const {
            return std::chrono::duration_cast<std::chrono::milliseconds>(m_delta_time).count();
        }
    };
}
