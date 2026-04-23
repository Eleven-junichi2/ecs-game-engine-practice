#include <tuple>
#include "Vec2.hpp"

class Component
{
};

struct CTransform : public Component
{
    Vec2<float> pos{0.0, 0.0};
    Vec2<float> prev_pos{0.0, 0.0};
    Vec2<float> velocity{0.0, 0.0};
    Vec2<float> scale{1.0, 1.0};
    float angle = 0;
};

class CBoundingBox : public Component
{
public:
    Vec2<float> size;
    Vec2<float> half_size;
    CBoundingBox(const Vec2<float> &s)
        : size{s}, half_size{s.x / 2, s.y / 2} {}
};

using ComponentTuple = std::tuple<CTransform, CBoundingBox>;