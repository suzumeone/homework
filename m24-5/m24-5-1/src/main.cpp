#include "logic.h"

int main()
{
    std::string input;
    std::string taskName;
    std::string curr_task = "\0";
    std::string prev_task = "\0";
    std::map<std::string, std::tm> tasks;
    std::map<std::string, std::tm> ended_tasks;

    readTasks(ended_tasks, tasks);

    while(true)
    {
        Clear();
        std::cout << "Start new task:\t\tbegin" << std::endl <<
                     "End current task:\tend" << std::endl << 
                   "Show tasks list:\tstatus" << std::endl <<
                        "Exit program:\t\texit\n" << std::endl;
        std::cout << ">>> ";
        std::cin >> input;
        if(input == "exit" || input == "EXIT" || input == "e" || input == "E")
            break;
        
        if(input == "begin" || input == "Begin" || input == "BEGIN")
        {
            prev_task = curr_task;
            std::cout << "Enter task name: ";
            std::cin.ignore();
            std::getline(std::cin, taskName);

            curr_task = taskName;

            std::time_t now = std::time(nullptr);
            std::tm tm = *std::localtime(&now);
            tasks.insert(std::pair<std::string, std::tm>(taskName, tm));
            if (prev_task != "\0")
            {
                std::cout << "Ending previous task..." << std::endl;
                endTask(prev_task, tasks, ended_tasks);
            }
            std::cout << "Task \"" << taskName << "\" started." << std::endl;

        }
        else if(input == "end" || input == "End" || input == "END")
        {
            std::cout << "Enter task name: ";
            std::cin.ignore();
            std::getline(std::cin, taskName);
            endTask(taskName, tasks, ended_tasks);
        }
        else if(input == "status" || input == "Status" || input == "STATUS")
        {
            std::cout << "*****Tasks list*****" << std::endl;
            std::cout << "\tEnded tasks:" << std::endl;
            for(const auto& task : ended_tasks)
                std::cout << "Task name: " << task.first << "\tTotal time: " << std::put_time(&task.second, "%H:%M:%S") << std::endl;
            std::cout << "\tCurrent task:" << std::endl;
            for (const auto& task : tasks)
                std::cout << "Task name: " << task.first << std::endl;
            std::cout << "********************" << std::endl;
        }
        else
        {
            std::cout << "Incorrect input." << std::endl;
            continue;
        }
        saveTasks(tasks, ended_tasks);
    }
}