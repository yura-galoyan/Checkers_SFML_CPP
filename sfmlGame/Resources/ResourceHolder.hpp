#ifndef RESORCES_RESOURCE_HOLDER_HPP
#define RESORCES_RESOURCE_HOLDER_HPP

#include <stdexcept>
#include <cassert>
#include <memory>
#include <map>

template<typename Resource, typename Id>
class ResourceHolder
{
public:
    ResourceHolder() = default;
    void load(const Id& id, const std::string& filepath ){
        auto resource = std::make_unique<Resource>();
        if(!resource.loadFromFile(filepath)){
            throw std::runtime_error{"could not load resource" + filepath};
        }
        auto inserted = resources.insert(std::make_pair(id,std::move(filepath)));
        assert(inserted.second);
    }

    Resource& get(const Id& id){
        auto found = mTextureMap.find(id);
        assert(found != mTextureMap.end());
        return *found->second;
    }

    const Resource& get(const Id& id) const{
        auto found = mTextureMap.find(id);
        assert(found != mTextureMap.end());
        return *found->second;
    }

private:
    std::map<Id, std::unique_ptr<Resource>> resources;
    
};



#endif //RESORCES_RESOURCE_HOLDER_HPP