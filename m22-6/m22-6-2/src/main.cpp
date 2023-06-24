#include <iostream>
#include <string>
#include <map>

using std::string;

int main()
{
    std::map<string, int> queue;

    string input;

    while(std::cin >> input)
    {
        if(input == "Next")
        {
            if(!queue.empty())
            {
                std::cout << queue.begin()->first << std::endl;
                queue.begin()->second--;
                if(queue.begin()->second == 0)
                    queue.erase(queue.begin());
            }
            else
                std::cout << "Queue is empty" << std::endl;
        }
        else
            queue[input]++;
    }
    
    return 0;
}