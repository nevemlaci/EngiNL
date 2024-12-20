#pragma once
#include "entt/entt.hpp"
#include "src/export.hpp"

namespace EngiNL{
    class Scene;
    class Entity;
}

namespace EngiNL {

class NLExport IScript {
    friend class Entity;
    entt::entity m_entity;
    Scene* m_scene;

    void init(entt::entity entity, Scene* scene) {
        m_entity = entity;
        m_scene = scene;
    }
public:
    explicit IScript() = default;
    IScript(IScript&&) = default;
    virtual ~IScript() = default;

    virtual void start() = 0;
    virtual void update() = 0;

    [[nodiscard]] Entity self() const;
};
} // EngiNL
