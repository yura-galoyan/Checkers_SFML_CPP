#ifndef ABSTACT_SYSTEM_FACTORY_HPP
#define ABSTACT_SYSTEM_FACTORY_HPP

#include "../System/Controller.hpp"
#include "../AbstractBoardModel.hpp"
#include "../AbstractBoardView.hpp"

#include <memory>

class AbstractSystemFactory
{
public:
    virtual std::unique_ptr<Controller> createController() = 0 ;
    virtual std::unique_ptr<AbstractBoardModel> createBoardModel() = 0 ;
    virtual std::unique_ptr<AbstractBoardView> createBoardView() = 0 ;
};

#endif //ABSTACT_SYSTEM_FACTORY_HPP
