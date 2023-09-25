#include "Window.hpp"
#include "../CellSizeController.hpp"
#include <iostream>

Window::Window(unsigned height_, unsigned width_, std::string title)
    :window{sf::VideoMode{width_, height_}, title},
     width{width_}, height{height_}
{ 
    window.setFramerateLimit(60);
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
    window.setPosition({150,50});
    auto size = sf::VideoMode().getDesktopMode().height;    
    size -= 150;
    size /= 8;
    size *= 8;
    CellSizeController::changeCellSizeTo(size / 8);

    std::cout <<size << std::endl;

    setSize({size,size});
}

void Window::setView(const sf::View &view){
    window.setView(view);
}

void Window::setSize(std::pair<unsigned, unsigned> size){
    window.setSize({size.first,size.second});
    auto view = window.getView();
    view.setSize(static_cast<float>(width),static_cast<float>(width));
    window.setView(view);
}

void Window::display(){
    window.display();
}
