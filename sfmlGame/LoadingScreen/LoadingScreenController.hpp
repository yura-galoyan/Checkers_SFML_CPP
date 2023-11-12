#ifndef LOADING_SCREEN_CONTROLLER_HPP
#define LOADING_SCREEN_CONTROLLER_HPP

#include "System/Window.hpp"
#include "System/Event.hpp"
#include "ChessJudge.hpp"
#include "../Interfaces/iController.hpp"

class AbstractBoardModel;

class LoadingScreenController : public iController
{
public:
    LoadingScreenController(Window& window, Event& event, AbstractBoardModel* model);

    void handleEvents() override ;

};


#endif //LOADING_SCREEN_CONTROLLER_HPP