#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "../System/Sprite.hpp"

#include <vector>

class BackGround
{
public:
    void draw(Window& window);
    void initSprites();
    void setTexture(Texture* texture);
    void setPosition(float x, float y) { m_pos = Vector2i(x,y); };
private:
    Sprite m_whiteCell;
    Sprite m_blackCell;
    Texture* m_texture;

private:
    Vector2i m_pos{0,0};
};


#endif //BACKGROUND_HPP