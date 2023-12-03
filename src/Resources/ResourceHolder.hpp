#ifndef RESORCES_RESOURCE_HOLDER_HPP
#define RESORCES_RESOURCE_HOLDER_HPP

#include <stdexcept>
#include <iostream>
#include <cassert>
#include <memory>
#include <map>

#include <filesystem>
namespace fs = std::filesystem;

template<typename Resource, typename Id>
class ResourceHolder
{
public:
    ResourceHolder() = default;
    void load(const Id& id, const std::string& filepath ){
        auto resource = std::make_unique<Resource>();

        if (!resource->loadFromFile(filepath)) {
            if (!resource->loadFromFile("../" + filepath)) {
                if (!resource->loadFromFile("../../" + filepath)) {
                    std::cout << "could not load from: " << "../../" + filepath <<"or " << "../" + filepath << " or " << filepath << std::endl;
                };
         
            };
        }

        auto inserted = resources.insert({id,std::move(resource)});
        // assert((*inserted).second);
    }

    Resource& get(const Id& id){
        auto found = resources.find(id);
        assert(found != resources.end());
        return *found->second;
    }

    const Resource& get(const Id& id) const{
        auto found = resources.find(id);
        assert(found != resources.end());
        return *found->second;
    }

private:
    std::map<Id, std::unique_ptr<Resource>> resources;

    
};



#endif //RESORCES_RESOURCE_HOLDER_HPP