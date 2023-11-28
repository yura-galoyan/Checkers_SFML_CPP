#ifndef VIEW_I_VIEW_HPP
#define VIEW_I_VIEW_HPP

#include "../System/Window.hpp"

#include "../Resources/ResourceHolder.hpp"
#include "../Resources/ResourceIds.hpp"
#include "../System/Texture.hpp"
#include "../System/Font.hpp"

using TextureHolder = ResourceHolder<Texture,TextureId>;
using TextureHolderPtr = std::unique_ptr<TextureHolder>;


using FontsHolder = ResourceHolder<Font, FontId>;
using FontsHolderPtr = std::unique_ptr<FontsHolder>;

class iView
{
public:
    iView(TextureHolderPtr textures, FontsHolderPtr fonts)
        : m_textures{std::move(textures)},
          m_fonts{std::move(fonts)}
        {}
    ~iView() { };
    TextureHolderPtr stealTextures() { return std::move(m_textures); }
    FontsHolderPtr stealFonts() { return std::move(m_fonts); }
    virtual void render(Window& window) = 0;
    virtual void init() = 0;

protected:
    TextureHolderPtr m_textures;
    FontsHolderPtr m_fonts;
};

#endif //VIEW_I_VIEW_HPP