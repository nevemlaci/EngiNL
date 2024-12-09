//
// Created by nevemlaci on 13/08/2024.
//

#include "AssetManager.hpp"


std::weak_ptr<SDL_Texture> EngiNL::AssetManager::LoadTexture(const std::string& name, const std::string& path) {
    SDL_Texture* new_texture = IMG_LoadTexture(*m_renderer, path.c_str());
    assert(new_texture!=nullptr);
    auto ret = m_textures.insert({name, std::shared_ptr<SDL_Texture>(new_texture, [](SDL_Texture* texture) {SDL_DestroyTexture(texture);} )});

    return ret.first->second;
}

EngiNL::AssetManager::AssetManager(SDL_Renderer** renderer) : m_renderer(renderer) {

}

std::weak_ptr<SDL_Texture> EngiNL::AssetManager::GetTexture(const std::string& name, const std::string& path) {
    if(path.empty()) {
        assert(m_textures.contains(name) && "No loaded asset with given name, and no path provided to load it from!");
        return m_textures.at(name);
    }else if(m_textures.contains(name)) {
        return  m_textures.at(name);
    }else {
        return LoadTexture(name, path);
    }
}

