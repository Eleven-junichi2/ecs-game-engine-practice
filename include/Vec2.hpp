template <typename T>
class Vec2
{
public:
    T x{};
    T y{};

    Vec2() = default;
    Vec2(T x, T y) : x{x}, y{y} {}

    bool operator==(const Vec2<T> &other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vec2<T> &other) const
    {
        return !(*this == other);
    }

    Vec2 operator+(const Vec2<T> &other) const
    {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator-(const Vec2<T> &other) const
    {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 operator*(const Vec2<T> &other) const
    {
        return Vec2(x * other.x, y * other.y);
    }

    Vec2 operator/(const Vec2<T> &other) const
    {
        return Vec2(x / other.x, y / other.y);
    }
};
