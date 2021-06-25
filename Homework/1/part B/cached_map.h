#include <map>
#include <memory>
#include <exception>

class DuplicateKeyException : std::exception
{
};
class ObjectNotExistException : std::exception
{
};

template <class K, class V>
class CacheMemory
{
public:
    CacheMemory(){}
    ~CacheMemory(){}

    void add(const K &key, const V &value)
    {
        if (!memory.emplace(key, new V(value)).second)
            throw DuplicateKeyException();
    }

    void erase(const K &key)
    {
        if (!memory.erase(key))
            throw ObjectNotExistException();
    }

    std::shared_ptr<V> get(const K &key)
    {
        auto weak = cache.find(key);
        if(weak == cache.end())
        {
            auto shared = memory.find(key);
            if(shared == memory.end())
                return nullptr;
            cache.emplace(shared->first, shared->second);
            return shared->second;
        }
        if(weak->second.expired())
        {
            cache.erase(weak);
            return nullptr;
        }
        return weak->second.lock();//std::shared_ptr<V>(weak->second);
    }

private:
    std::map<K, std::shared_ptr<V>> memory;
    std::map<K, std::weak_ptr<V>> cache;
};