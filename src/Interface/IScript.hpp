//
// Created by nevemlaci on 09/12/2024.
//

#pragma once
#include "../export.hpp"
#include "entt/entt.hpp"
namespace EngiNL{
    class NLExport Scene;
    class NLExport Entity;
}


namespace EngiNL{
struct NLExport IScript{
    friend class NLExport Entity;
    IScript() = default;
    virtual ~IScript() = default;

    virtual void start(Scene* scene) = 0;
    virtual void update(Scene* scene) = 0;

    void call_start(this auto&& self, Scene* scene) {
        self.start();
    }

    void call_update(this auto&& self, Scene* scene) {
        self.update();
    }

    [[nodiscard]] Entity self() const;

    private:
        IScript(entt::entity self, Scene* scene);
        entt::entity m_self;
        Scene* m_scene;
};


}
