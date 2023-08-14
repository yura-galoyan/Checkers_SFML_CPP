#include "AbstractBoardView.hpp"

#include "AbstractBoardModel.hpp"

void AbstractBoardView::setModel(std::unique_ptr<AbstractBoardModel> model_){
    this->model = std::move(model_);
}