#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP



#include <unordered_map>
#include <string>

#include "../ChessJudge.hpp"
#include "Window.hpp"

class AbstractBoardModel;

class Controller
{
private:
    struct Key{
        Key() = default;
        bool notTouched{false};
        bool clicked{false};
        bool onHold{false};
        bool shortReleased{true};    
        bool longReleased{true};    
    };

public:
    template<typename MouseButton>
    struct ButtonPair{
        MouseButton button;
        Key state;
    };

public:
    //template method
    void queryEvents(Window& window, Event& event);
    void setModel(AbstractBoardModel* model);

protected:
    virtual void setFlags(Window& window, Event& event) = 0;
    virtual void initMouseButtons() = 0;
    
protected:
    std::unordered_map<char, ButtonPair<char> > mouseButtons;

private:
    ChessJudge judge;
    AbstractBoardModel* model;
};


#endif //CONTROLLER_HPP
