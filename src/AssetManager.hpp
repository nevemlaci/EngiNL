//
// Created by nevemlaci on 13/08/2024.
//

#pragma once
#include <cassert>
#include <memory>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <unordered_map>
#include "export.hpp"

using std::literals::string_literals::operator""s;

namespace EngiNL{


    class NLExport AssetManager{
            SDL_Renderer** m_renderer;
            std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> m_textures;
            std::weak_ptr<SDL_Texture> LoadTexture(const std::string& name, const std::string& path);
        public:
            explicit AssetManager(SDL_Renderer** renderer);
            ~AssetManager() = default;

            std::weak_ptr<SDL_Texture> GetTexture(const std::string& name, const std::string& path = ""s);

    };
}
