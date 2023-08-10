#ifndef ABSTRACT_BOARD_VIEW_HPP
#define ABSTRACT_BOARD_VIEW_HPP

class AbstractBoardModel;
class AbstractBoardView
{
public:
    void setModel(AbstractBoardModel* model);


protected:
    AbstractBoardModel* model;

};

#endif //ABSTRACT_BOARD_VIEW_HPP