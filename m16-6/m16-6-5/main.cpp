#include <iostream>
#include <sstream>
#include <string>

enum switches
{
    POWER = 1,
    LIGHTS_INSIDE = 2,
    LIGHTS_OUTSIDE = 4,
    HEATERS = 8,
    WATER_PIPE_HEATING = 16,
    CONDITIONER = 32
};

int main() 
{
    int switches_state = 0;
    int outside_temperature = 0;
    int inside_temperature = 0;
    bool motion_detected = false;
    bool inside_lights_on = false;

    for (int day = 1; day <= 2; ++day) 
    {
        for (int hour = 0; hour < 24; ++hour) 
        {
            std::cout << "Day " << day << ", Time " << hour << ":00" << std::endl;
            std::string input;
            std::getline(std::cin, input);
            std::istringstream iss(input);

            iss >> outside_temperature >> inside_temperature;
            std::string motion;
            iss >> motion;
            motion_detected = (motion == "yes");

            std::string lights_inside;
            iss >> lights_inside;
            inside_lights_on = (lights_inside == "on");

            if (outside_temperature < 0 && !(switches_state & WATER_PIPE_HEATING))
            {
                switches_state |= WATER_PIPE_HEATING;
                std::cout << "Water heating on" << std::endl;
            }
            else if (outside_temperature > 5 && (switches_state & WATER_PIPE_HEATING))
            {
                switches_state &= ~WATER_PIPE_HEATING;
                std::cout << "Water heating off" << std::endl;
            }
            if (hour >= 16 && hour < 5 && motion_detected && !(switches_state & LIGHTS_OUTSIDE))
            {
                switches_state |= LIGHTS_OUTSIDE;
                std::cout << "Garden lighting on" << std::endl;
            }
            else if ((hour < 16 || hour >= 5 || !motion_detected) && (switches_state & LIGHTS_OUTSIDE))
            {
                switches_state &= ~LIGHTS_OUTSIDE;
                std::cout << "Garden lighting off" << std::endl;
            }
            if (inside_temperature < 22 && !(switches_state & HEATERS))
            {
                switches_state |= HEATERS;
                std::cout << "Room heating on" << std::endl;
            }
            else if (inside_temperature >= 25 && (switches_state & HEATERS))
            {
                switches_state &= ~HEATERS;
                std::cout << "Room heating off" << std::endl;
            }
            if (inside_temperature >= 30 && !(switches_state & CONDITIONER))
            {
                switches_state |= CONDITIONER;
                std::cout << "Air conditioning on" << std::endl;
            }
            else if (inside_temperature <= 25 && (switches_state & CONDITIONER))
            {
                switches_state &= ~CONDITIONER;
                std::cout << "Air conditioning off" << std::endl;
            }
            if (inside_lights_on && hour >= 16 && hour < 20)
            {
                int color_temperature = 5000 - ((hour - 16) * 500);
                std::cout << "Current color temperature of lighting inside the house: " << color_temperature << "K" << std::endl;
            }
            if (hour == 0 && (switches_state & LIGHTS_INSIDE))
            {
                std::cout << "Resetting the color temperature of indoor lighting to 5000K" << std::endl;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}