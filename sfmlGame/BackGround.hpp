#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "System/Sprite.hpp"

#include <vector>

class BackGround
{
public:
    void draw(Window& window);
    void initSprites(float , Texture& texture);

private:
    std::vector<Sprite> sprites;
};


#endif //BACKGROUND_HPP