#ifndef I_BOARD_VIEW_HPP
#define I_BOARD_VIEW_HPP

#include <SFML/Graphics/RectangleShape.hpp>

#include "RegularBoardModel.hpp"

class iBoardView
{
public:
    iBoardView() = default;
    iBoardView(std::shared_ptr<RegularBoardModel> model)
     :m_model{model}
    {

    };

public:
    virtual void draw(Window& window) = 0;

public:
    void setModel(std::shared_ptr<RegularBoardModel> model) {
        m_model = model;
    };

protected:
    std::shared_ptr<RegularBoardModel> m_model;

};


#endif //I_BOARD_VIEW_HPP