//
// Created by nevemlaci on 09/12/2024.
//

#pragma once
#include "../export.hpp"
#include <memory>

#include "src/Interface/IScript.hpp"

namespace EngiNL{
    class NLExport Scene;

}

namespace EngiNL::Component{
    struct NLExport CustomScript{
        std::unique_ptr<IScript> script;
    };
}
