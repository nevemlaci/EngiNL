//
// Created by nevemlaci on 10/08/2024.
//

#pragma once

#include "export.hpp"
#include <queue>

#include <SDL3/SDL.h>

#include "AssetManager.hpp"
#include "Scene.hpp"


namespace EngiNL{
    class NLExport Engine{
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        AssetManager m_asset_manager;

    public:
        [[nodiscard]] SDL_Window* GetWindow() const { return m_window; }
        [[nodiscard]] SDL_Renderer* GetRenderer() const { return m_renderer; }

    private:
        std::queue<Scene> m_scene_queue;
    public:
        Engine();
        ~Engine();
        Engine(const Engine&) = delete;
        Engine(Engine&&) = delete;
        Engine& operator=(const Engine&) = delete;
        Engine& operator=(Engine&&) = delete;

        Scene& PushScene();
        Scene& GetCurrentScene();

        AssetManager& GetAssetManager() {
            return m_asset_manager;
        }

        void Run();
    };
}
