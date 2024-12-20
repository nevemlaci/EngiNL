//
// Created by nevemlaci on 11/12/2024.
//

#pragma once
#include <memory>
#include <vector>

#include "src/export.hpp"
#include "src/Interface/iscript.hpp"

namespace EngiNL{
    class Scene;

    struct NLExport ScriptHolder{
        std::vector<std::unique_ptr<IScript>> m_scripts;

        static void start_system(Scene* scene);

        static void update_system(Scene* scene);

        ScriptHolder() = default;
        ScriptHolder(const ScriptHolder&) = delete;
        ScriptHolder(ScriptHolder&&) = default;

        ScriptHolder& operator=(const ScriptHolder&) = delete;
        ScriptHolder& operator=(ScriptHolder&&) = default;
    };
}
