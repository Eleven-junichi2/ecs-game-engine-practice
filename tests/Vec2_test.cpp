#include <iostream>
#include "Vec2.hpp"

int main()
{
    const Vec2<int> v_a{1, 1};
    const Vec2<int> v_b{2, 3};

    if (!(v_a + v_b == Vec2<int>{3, 4}))
    {
        return 1;
    }

    if (!(v_b - v_a == Vec2<int>{1, 2}))
    {
        return 1;
    }

    if (!(v_a * v_b == Vec2<int>{2, 3}))
    {
        return 1;
    }

    if (!(v_b / v_a == Vec2<int>{2, 3}))
    {
        return 1;
    }

    if (!(v_a == Vec2<int>{1, 1}))
    {
        return 1;
    }

    if (!(v_a != v_b))
    {
        return 1;
    }

    return 0;
}
