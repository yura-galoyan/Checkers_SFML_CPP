#include "SfmlSystemFactory.hpp"

std::unique_ptr<AbstractBoardModel> SfmlSystemFactory::createBoardModel(){
    return std::make_unique<RegularBoardModel>();
}

std::unique_ptr<AbstractBoardView> SfmlSystemFactory::createBoardView()
{
    return std::make_unique<RegularBoardView>();
}

std::unique_ptr<Controller> SfmlSystemFactory::createController()
{
    return std::make_unique<SfmlController>();
}
