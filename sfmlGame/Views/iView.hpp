#ifndef VIEW_I_VIEW_HPP
#define VIEW_I_VIEW_HPP

#include "../System/Window.hpp"

#include "../Resources/ResourceHolder.hpp"
#include "../Resources/ResourceIds.hpp"
#include "../System/Texture.hpp"

using TextureHolder = std::unique_ptr<ResourceHolder<Texture,TextureId>>; 

class iView
{
public:
    iView(TextureHolder textures)
        : m_textures{std::move(textures)}
        {}

    TextureHolder stealTextures() { return std::move(m_textures); }

    virtual void render(Window& window) = 0;
    virtual void init() = 0;

protected:
    TextureHolder m_textures;
};


#endif //VIEW_I_VIEW_HPP