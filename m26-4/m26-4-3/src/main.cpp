#include <iostream>
#include <string>
#include "color.hpp"

class Window
{
private:

    int m_window_heigh = 0;
    int m_window_width = 0;
    int m_widow_pos_x = 0;
    int m_widow_pos_y = 0;

public:
    struct Vec
    {
        int x = 0;
        int y = 0;
    };

    Vec fillVector()
    {
        int x;
        int y; 
        std::cout << "Width | X: ";
        std::cin >> y;
        std::cout << "Height | Y: ";
        std::cin >> x;
        Vec vec;
        vec.x = x;
        vec.y = y;
        return vec;
    }

    void set_size(Vec size)
    {
        if(m_widow_pos_x + size.x > 50) size.x = 50 - m_widow_pos_x;
        if(size.x < 0)                  size.x = 1;
        if(m_widow_pos_y + size.y > 80) size.y = 80 - m_widow_pos_y;
        if(size.y < 0)                  size.y = 1;

        m_window_heigh = size.x;
        m_window_width = size.y;
    }

    Vec get_size()
    {
        Vec size;
        size.x = m_window_heigh;
        size.y = m_window_width;
        return size;
    }

    void set_pos(Vec pos)
    {
        if(pos.x > 50)  pos.x = 50;
        if(pos.x <  0)  pos.x = 0;
        if(pos.y > 80)  pos.y = 80;
        if(pos.y <  0)  pos.y = 0;

        m_widow_pos_x = pos.x;
        m_widow_pos_y = pos.y;
    }

    Vec get_pose()
    {
        Vec pos;
        pos.x = m_widow_pos_x;
        pos.y = m_widow_pos_y;
        return pos;
    }
};

class Display
{
private:
    //Private fields
    const int m_height = 50;
    const int m_width = 80;

    //Private methods
    void display(Window::Vec window_size, Window::Vec window_pos)
    {
        int pixel = 0;
        for(int i = 0; i <= 50; i++)
        {
            for(int j = 0; j <= 80; j++)
            {
                if (window_size.x != 0 || window_size.y != 0)
                {
                    if ((i >= window_pos.x && i <= window_pos.x + window_size.x) && (j >= window_pos.y && j <= window_pos.y + window_size.y))
                    {
                        pixel = 1;
                        std::cout << colors::bright_green;
                    }
                    else
                    {
                        pixel = 0;
                        std::cout << colors::reset;
                    }

                }
                std::cout << pixel << " ";
            }
            std::cout << std::endl;
        }
        std::cout << colors::reset;
    }
public:
    void turn_on()
    {
        Window window;
        Window::Vec vec;
        while (true)
        {
            std::cout << "Monitor: move, resize, display, close" << std::endl;
            std::cout << ">>> ";
            std::string input;
            std::cin >> input;
            if (input == "close")
            {
                delete& window;
                break;
            }
            else if(input == "move")
                window.set_pos(window.fillVector());
            else if(input == "resize")
                window.set_size(window.fillVector());
            else if(input == "display")
                display(window.get_size(), window.get_pose());
            std::cin.clear();
        }

        
    }
};

int main()
{
    
    Display monitor;
    monitor.turn_on();
    delete& monitor;
    return 0;
}