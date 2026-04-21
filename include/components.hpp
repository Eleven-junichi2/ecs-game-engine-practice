#include <tuple>
#include "Vec2.hpp"

class Component
{
};

class CTransform : Component
{
public:
    Vec2<int> pos{0, 0};
    Vec2<int> velocity{0, 0};
    CTransform() = default;
    CTransform(const Vec2<int> &pos, const Vec2<int> &velocity)
        : pos{pos}, velocity{velocity} {}
};

using ComponentTuple = std::tuple<CTransform>;