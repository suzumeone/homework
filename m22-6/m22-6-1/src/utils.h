#pragma once
#include <iostream>
#include <string>
#include <map>

void clean(std::string& data, std::string& number, std::string& surname);
bool checkNumber(std::string& number);
bool checkSurname(std::string& surname);
bool SeparateData(std::string& data, std::string& number, std::string& surname);
