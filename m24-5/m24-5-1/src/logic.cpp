#include "logic.h"

void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void separatestr(std::string line, std::string& taskName, std::tm& taskTime)
{
    size_t separatorPos = line.find(",");
    if (separatorPos != std::string::npos)
    {
        taskName = line.substr(0, separatorPos);
        std::string time = line.substr(separatorPos + 1, strlen(line.c_str()));
        if (time[2] == ':')
        {
            taskTime.tm_hour = stoi(time.substr(0, 2));
            taskTime.tm_min = stoi(time.substr(3, 2));
            taskTime.tm_sec = stoi(time.substr(6, 2));
        }
        else
        {
            std::time_t t = stod(time);
            taskTime = *std::localtime(&t);
        }
    }
}

void saveTasks(std::map<std::string, std::tm>& tasks, std::map<std::string, std::tm>& etasks)
{
    remove("tasks");
    std::ofstream save("tasks", std::ios_base::app);
    if (!save.is_open())
    {
        //std::cout << "File creation error." << std::endl;
        save.close();
        return;
    }
    save << "Ended tasks:\n";
    for (const auto& task : etasks)
        save << task.first << "," << std::put_time(&task.second, "%H:%M:%S") << "\n";
    save << "Current task:\n";
    for (auto& task : tasks)
        save << task.first << "," << std::mktime(&task.second);

    save.close();
    //std::cout << "Data saved successfully." << std::endl;

}

void readTasks(std::map<std::string, std::tm>& etasks, std::map<std::string, std::tm>& tasks)
{
    std::ifstream ftasks("tasks");
    if (!ftasks.is_open())
    {
        //std::cout << "History not found." << std::endl;
        ftasks.close();
        return;
    }
    std::string line;
    std::cin.ignore();
    bool is_current = false;
    while (std::getline(ftasks, line))
    {
        if (line == "Ended tasks:")
            continue;
        if (line == "Current task:")
        {
            is_current = true;
            continue;
        }

        std::string taskName;
        std::tm tm{0};

        separatestr(line, taskName, tm);

        if (is_current)
            tasks.insert(std::pair<std::string, std::tm>(taskName, tm));
        else
            etasks.insert(std::pair<std::string, std::tm>(taskName, tm));

    }
    ftasks.close();
}

void ssToHMS(int& ss, int& hh, int& mm, int totalSeconds)
{
    hh = totalSeconds / 3600;
    int secondsWithoutHours = totalSeconds % 3600;
    mm = secondsWithoutHours / 60;
    ss = secondsWithoutHours % 60;
}

void endTask(std::string& taskName, std::map<std::string, std::tm>& tasks, std::map<std::string, std::tm>& etasks)
{
    int hh, mm, ss;
    const auto& it = tasks.find(taskName);
    if (it != tasks.end())
    {
        std::cout << "Task \"" << it->first << "\" done." << std::endl;
        std::time_t s_end_time = std::time(nullptr);
        double diff_t = std::difftime(s_end_time, mktime(&it->second));
        ssToHMS(ss, hh, mm, int(diff_t));
        std::tm tm{0};
        tm.tm_hour = hh;
        tm.tm_min = mm;
        tm.tm_sec = ss;
        std::cout << "Task total time: " << std::put_time(&tm, "%H:%M:%S") << std::endl;
        etasks.insert(std::pair<std::string, std::tm>(it->first, tm));
        tasks.erase(it);
    }
    else
        std::cout << "Task not found." << std::endl;
}