#ifndef VIEW_I_VIEW_HPP
#define VIEW_I_VIEW_HPP

#include "../System/Window.hpp"

#include "../Resources/ResourceHolder.hpp"
#include "../Resources/ResourceIds.hpp"
#include "../System/Texture.hpp"

using TextureHolder = ResourceHolder<Texture,TextureId>;
using TextureHolderPtr = std::unique_ptr<TextureHolder>;

class iView
{
public:
    iView(TextureHolderPtr textures)
        : m_textures{std::move(textures)}
        {}

    TextureHolderPtr stealTextures() { return std::move(m_textures); }

    virtual void render(Window& window) = 0;
    virtual void init() = 0;

protected:
    TextureHolderPtr m_textures;
};

#endif //VIEW_I_VIEW_HPP