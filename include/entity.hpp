#include <string>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>
#include "components.hpp"

class Entity
{
    ComponentTuple m_components{};
    bool m_alive{true};
    std::string m_tag{"default"};
    size_t m_id{0};

public:
    Entity() = default;
    Entity(std::string tag, size_t id)
        : m_tag{tag}, m_id{id} {}

    // template <typename T, typename... TArgs>
    // T &add(TArgs &&...args);

    // template <typename T>
    // T &get();

    // template <typename T>
    // const T &get() const;

    // template <typename T>
    // bool has() const;

    // template <typename T>
    // void remove();

    // size_t id() const;
    bool isAlive() const
    {
        return m_alive;
    }
    void destroy();
    const std::string &tag() const
    {
        return m_tag;
    }
};

using EntityVec = std::vector<std::shared_ptr<Entity>>;
using EntityMap = std::map<std::string, EntityVec>;

class EntityManager
{
    EntityVec m_entities{};
    EntityVec m_toAdd{};
    EntityMap m_entityMap{};
    size_t m_totalEntites = 0;

public:
    EntityManager();
    void update()
    {
        for (auto &e : m_toAdd)
        {
            m_entities.push_back(e);
            m_entityMap[e->tag()].push_back(e);
        }
        m_toAdd.clear();

        m_entities.erase(
            std::remove_if(
                m_entities.begin(),
                m_entities.end(),
                [](const auto &e)
                { return !(e->isAlive()); }),
            m_entities.end());

        for (auto &[tag, entities] : m_entityMap)
        {
            entities.erase(
                std::remove_if(
                    entities.begin(),
                    entities.end(),
                    [](const auto &e)
                    { return !(e->isAlive()); }),
                entities.end());
        }
    }
    std::shared_ptr<Entity> addEntity(const std::string &tag)
    {
        auto e = std::make_shared<Entity>(tag, m_totalEntites++);
        m_toAdd.push_back(e);
        return e;
    }
    EntityVec &getEntities()
    {
        return m_entities;
    }
    EntityVec &getEntities(const std::string &tag)
    {
        return m_entityMap[tag];
    }
};
