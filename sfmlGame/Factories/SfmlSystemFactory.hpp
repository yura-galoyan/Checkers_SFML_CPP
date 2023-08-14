#ifndef SFML_SYSTEM_FACTORY_HPP
#define SFML_SYSTEM_FACTORY_HPP

#include "AbstractSystemFactory.hpp"

#include "../System/SfmlController.hpp"
#include "../RegularBoardModel.hpp"
#include "../RegularBoardView.hpp"

class SfmlSystemFactory : public AbstractSystemFactory
{
public:
    std::unique_ptr<AbstractBoardModel> createBoardModel() override ;
    std::unique_ptr<AbstractBoardView> createBoardView() override ;
    std::unique_ptr<Controller> createController() override ;
};



#endif //SFML_SYSTEM_FACTORY_HPP