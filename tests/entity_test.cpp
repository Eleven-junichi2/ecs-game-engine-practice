#include <iostream>
#include "entity.hpp"

int main()
{
    EntityManager entity_manager{};
    entity_manager.addEntity("default");
    EntityVec& entities_refer {entity_manager.getEntities()};
    entity_manager.update();
    if (!(entities_refer[0]->tag() == "default")) {
        std::cerr << "Failed to see the entity which has \"default\" tag." << std::endl;
        return 1;
    }
    return 0;
}