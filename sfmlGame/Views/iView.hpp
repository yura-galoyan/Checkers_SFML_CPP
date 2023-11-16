#ifndef VIEW_I_VIEW_HPP
#define VIEW_I_VIEW_HPP

#include "../System/Window.hpp"

class iView
{
public:
    virtual void render(Window& window) = 0;
};


#endif //VIEW_I_VIEW_HPP