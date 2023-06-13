#include <iostream>
#include <cmath>

struct Vector2D 
{
    double x;
    double y;
};

Vector2D add(const Vector2D& v1, const Vector2D& v2) 
{
    Vector2D result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
}

Vector2D subtract(const Vector2D& v1, const Vector2D& v2) 
{
    Vector2D result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    return result;
}

Vector2D scale(const Vector2D& v, double scalar) 
{
    Vector2D result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    return result;
}

double length(const Vector2D& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

Vector2D normalize(const Vector2D& v) 
{
    double len = length(v);
    Vector2D result;
    result.x = v.x / len;
    result.y = v.y / len;
    return result;
}

int main()
{
    std::string operation;
    std::cout << "Enter operation (add, subtract, scale, length, normalize): ";
    std::cin >> operation;

    Vector2D v1, v2, result;
    double scalar;

    if (operation == "add" || operation == "subtract")
    {
        std::cout << "Enter first vector (x y): ";
        std::cin >> v1.x >> v1.y;
        std::cout << "Enter second vector (x y): ";
        std::cin >> v2.x >> v2.y;
    }
    else if (operation == "scale")
    {
        std::cout << "Enter vector (x y): ";
        std::cin >> v1.x >> v1.y;
        std::cout << "Enter scalar value: ";
        std::cin >> scalar;
    }
    else if (operation == "length" || operation == "normalize")
    {
        std::cout << "Enter vector (x y): ";
        std::cin >> v1.x >> v1.y;
    }
    else
    {
        std::cout << "Invalid operation." << std::endl;
        return 0;
    }

    if (operation == "add")
    {
        result = add(v1, v2);
        std::cout << "Result: (" << result.x << ", " << result.y << ")" << std::endl;
    }
    else if (operation == "subtract") 
    {
        result = subtract(v1, v2);
        std::cout << "Result: (" << result.x << ", " << result.y << ")" << std::endl;
    }
    else if (operation == "scale") 
    {
        result = scale(v1, scalar);
        std::cout << "Result: (" << result.x << ", " << result.y << ")" << std::endl;
    }
    else if (operation == "length") 
    {
        double len = length(v1);
        std::cout << "Length: " << len << std::endl;
    }
    else if (operation == "normalize") 
    {
        result = normalize(v1);
        std::cout << "Normalized vector: (" << result.x << ", " << result.y << ")" << std::endl;
    }

    return 0;
}
