//
// Created by nevemlaci on 10/08/2024.
//

#include "Engine.hpp"
#include <iostream>

EngiNL::Engine::Engine() : m_window(nullptr), m_renderer(nullptr), m_asset_manager(&m_renderer) {

    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS);

    m_window = SDL_CreateWindow("", 800, 600,SDL_WINDOW_HIDDEN);

    auto numdriv = SDL_GetNumRenderDrivers();
    for(auto i = 0; i < numdriv; ++i) {
        std::cout << SDL_GetRenderDriver(i) << '\n';
    }
    m_renderer = SDL_CreateRenderer(m_window, "vulkan");
    SDL_ShowWindow(m_window);
}

EngiNL::Engine::~Engine() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
}

EngiNL::Scene& EngiNL::Engine::PushScene() {
    return m_scene_queue.emplace(this);
}

EngiNL::Scene& EngiNL::Engine::GetCurrentScene() {
    return m_scene_queue.front();
}

void EngiNL::Engine::Run() {
    while(!m_scene_queue.empty()) {
        m_scene_queue.front().Update();
        m_scene_queue.pop();
    }
}
