//
// Created by nevemlaci on 09/12/2024.
//

#pragma once
#include "src/EngiNL.hpp"

struct Script : EngiNL::IScript{
    using IScript::IScript;
    std::string name = "example";

    virtual void start(EngiNL::Scene* scene) override {
        std::print(std::cout, "{} script start", name);
    }

    virtual void update(EngiNL::Scene* scene) override {

    }

    virtual ~Script() override = default;
};