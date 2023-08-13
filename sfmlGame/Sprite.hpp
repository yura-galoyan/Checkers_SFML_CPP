#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <utility>

#include "Texture.hpp"

class Sprite
{
    void setTexture(Texture& texture);

public:
    std::reference_wrapper<Texture> texture;
};


#endif //SPRITE_HPP