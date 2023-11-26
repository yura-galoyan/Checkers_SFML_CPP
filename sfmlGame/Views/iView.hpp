#ifndef VIEW_I_VIEW_HPP
#define VIEW_I_VIEW_HPP

#include "../System/Window.hpp"

#include "../Resources/ResourceHolder.hpp"
#include "../Resources/ResourceIds.hpp"
#include "../System/Texture.hpp"
#include "../System/Font.hpp"

using TextureHolder = ResourceHolder<Texture,TextureId>;
using TextureHolderPtr = std::unique_ptr<TextureHolder>;


using FontHolder = ResourceHolder<Font, FontId>;
using FontHolderPtr = std::unique_ptr<FontHolder>;

class iView
{
public:
    iView(TextureHolderPtr textures, FontHolderPtr fonts)
        : m_textures{std::move(textures)},
          m_fonts{std::move(fonts)}
        {}

    TextureHolderPtr stealTextures() { return std::move(m_textures); }

    virtual void render(Window& window) = 0;
    virtual void init() = 0;

protected:
    TextureHolderPtr m_textures;
    FontHolderPtr m_fonts;
};

#endif //VIEW_I_VIEW_HPP