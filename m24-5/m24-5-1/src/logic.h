#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <map>

void Clear();
void separatestr(std::string line, std::string& taskName, std::tm& taskTime);
void saveTasks(std::map<std::string, std::tm>& tasks, std::map<std::string, std::tm>& etasks);
void readTasks(std::map<std::string, std::tm>& etasks, std::map<std::string, std::tm>& tasks);
void ssToHMS(int& ss, int& hh, int& mm, int totalSeconds);
void endTask(std::string& taskName, std::map<std::string, std::tm>& tasks, std::map<std::string, std::tm>& etasks);