#include "Window.hpp"

Window::Window(unsigned height, unsigned width, std::string title)
    :window{sf::VideoMode{width, height}, title}
{
}

void Window::draw(const sf::Drawable& drawable){
    window.draw(drawable);
}

bool Window::pollEvent(Event &event){   
   return window.pollEvent(event.event());
}

bool Window::isOpen(){
   return window.isOpen();
}

void Window::close(){
    window.close();
}

void Window::clear(){
    window.clear();
}

void Window::display(){
    window.display();
}
