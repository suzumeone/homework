#pragma once
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string checkTable(string table);
string getWinner(string board);
char getWinnerInRow(string row);
char getWinnerInColumn(string board, int column);
char getWinnerInDiagonal(string board, bool work);
bool isValidBoard(string board);
