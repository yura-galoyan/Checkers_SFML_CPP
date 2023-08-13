#include "LoadingScreen.hpp"

void LoadingScreen::start(Controller& c,Window& w,Event& e){
    while(w.isOpen()){
        c.queryEvents(w, e);
        
    }
}