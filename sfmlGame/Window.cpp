#include "Window.hpp"

Window::Window(unsigned height_, unsigned width_, std::string title)
    :window{sf::VideoMode{width_, height_}, title},
     width{width_}, height{height_}
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

void Window::create(unsigned height_, unsigned width_, std::string title){
    width = width_;
    height = height_;
    window.create(sf::VideoMode{height, width}, title);
}

void Window::display(){
    window.display();
}
