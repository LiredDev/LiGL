class Vector2 {
public:
    int X;
    int Y;
     Vector2(int x, int y) {
        X = x;
        Y = y;
    };
     // Overload the + operator for addition
    Vector2 operator+(const Vector2& v) const {
        return Vector2(X + v.X, Y + v.Y);
    }
     // Overload the - operator for subtraction
    Vector2 operator-(const Vector2& v) const {
        return Vector2(X - v.X, Y - v.Y);
    }
     // Overload the * operator for scalar multiplication
    Vector2 operator*(int value) const {
        return Vector2(X * value, Y * value);
    }
     // Overload the / operator for scalar division
    Vector2 operator/(int value) const {
        return Vector2(X / value, Y / value);
    }
     // Overload the == operator for equality comparison
    bool operator==(const Vector2& v) const {
        return (X == v.X && Y == v.Y);
    }
     // Overload the != operator for inequality comparison
    bool operator!=(const Vector2& v) const {
        return !(*this == v);
    }
};
 class Vector3 {
public:
    int X;
    int Y;
    int Z;
     Vector3(int x, int y, int z) {
        X = x;
        Y = y;
        Z = z;
    };
     // Overload the + operator for addition
    Vector3 operator+(const Vector3& v) const {
        return Vector3(X + v.X, Y + v.Y, Z + v.Z);
    }
     // Overload the - operator for subtraction
    Vector3 operator-(const Vector3& v) const {
        return Vector3(X - v.X, Y - v.Y, Z - v.Z);
    }
     // Overload the * operator for scalar multiplication
    Vector3 operator*(int value) const {
        return Vector3(X * value, Y * value, Z * value);
    }
     // Overload the / operator for scalar division
    Vector3 operator/(int value) const {
        return Vector3(X / value, Y / value, Z / value);
    }
     // Overload the == operator for equality comparison
    bool operator==(const Vector3& v) const {
        return (X == v.X && Y == v.Y && Z == v.Z);
    }
     // Overload the != operator for inequality comparison
    bool operator!=(const Vector3& v) const {
        return !(*this == v);
    }
};
 class Vector2f {
public:
    float X;
    float Y;
     Vector2f(float x, float y) {
        X = x;
        Y = y;
    };
     // Overload the + operator for addition
    Vector2f operator+(const Vector2f& v) const {
        return Vector2f(X + v.X, Y + v.Y);
    }
     // Overload the - operator for subtraction
    Vector2f operator-(const Vector2f& v) const {
        return Vector2f(X - v.X, Y - v.Y);
    }
     // Overload the * operator for scalar multiplication
    Vector2f operator*(float value) const {
        return Vector2f(X * value, Y * value);
    }
     // Overload the / operator for scalar division
    Vector2f operator/(float value) const {
        return Vector2f(X / value, Y / value);
    }
     // Overload the == operator for equality comparison
    bool operator==(const Vector2f& v) const {
        return (X == v.X && Y == v.Y);
    }
     // Overload the != operator for inequality comparison
    bool operator!=(const Vector2f& v) const {
        return !(*this == v);
    }
};
 class Vector3f {
public:
    float X;
    float Y;
    float Z;
     Vector3f(float x, float y, float z) {
        X = x;
        Y = y;
        Z = z;
    };
    Vector3f() : X(0.0f), Y(0.0f), Z(0.0f) {}
     // Overload the + operator for addition
    Vector3f operator+(const Vector3f& v) const {
        return Vector3f(X + v.X, Y + v.Y, Z + v.Z);
    }
     // Overload the - operator for subtraction
    Vector3f operator-(const Vector3f& v) const {
        return Vector3f(X - v.X, Y - v.Y, Z - v.Z);
    }
     // Overload the * operator for scalar multiplication
    Vector3f operator*(float value) const {
        return Vector3f(X * value, Y * value, Z * value);
    }
     // Overload the / operator for scalar division
    Vector3f operator/(float value) const {
        return Vector3f(X / value, Y / value, Z / value);
    }
     // Overload the == operator for equality comparison
    bool operator==(const Vector3f& v) const {
        return (X == v.X && Y == v.Y && Z == v.Z);
    }
     // Overload the != operator for inequality comparison
    bool operator!=(const Vector3f& v) const {
        return !(*this == v);
    }
};