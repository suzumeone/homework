#include <iostream>

int main() 
{
    const double delta = 0.01;
    double speed = 0.0;
    char speed_str[10];

    do 
    {
        std::cout << "Enter delta in speed (negative value for deceleration): ";
        double delta_speed;
        std::cin >> delta_speed;

        speed += delta_speed;
        if (speed < 0.0)
            speed = 0.0;
        else if (speed > 150.0)
            speed = 150.0;

        sprintf_s(speed_str, "%.1f", speed);
        std::cout << "Speed: " << speed_str << " km/h" << std::endl;
    } 
    while (speed > delta);

    std::cout << "The car is stopped." << std::endl;

    return 0;
}