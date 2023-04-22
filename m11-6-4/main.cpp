#include "main.h"

int main()
{
    string table, row;

    for (int i = 0; i < 3; i++)
    {
        std::getline(cin, row);
        table += row + '\n';
    }

    cout << checkTable(table) << endl;

    return 0;

}

string checkTable(string table)
{
	string row1 = "", row2 = "", row3 = "";
	int nlCtr = 0;
	for (int i = 0; i < table.length(); i++)
	{
        if (table[i] == ' ')
            continue;
        if (table[i] == '\n')
		{
			nlCtr++;
			continue;
		}
		else if (nlCtr == 0)
			row1 += table[i];
		else if (nlCtr == 1)
			row2 += table[i];
		else if (nlCtr == 2)
			row3 += table[i];
		else
			continue;
	}

    string winner = getWinner(row1 + row2 + row3);
    return winner;
}

char getWinnerInRow(string row) {
    char winner = '.';
    if (row[0] == row[1] && row[1] == row[2]) {
        winner = row[0];
    }
    return winner;
}

char getWinnerInColumn(string board, int column) {
    char winner = '.';
    if (board[column] == board[column + 3] && board[column + 3] == board[column + 6]) {
        winner = board[column];
    }
    return winner;
}

char getWinnerInDiagonal(string board, bool work) {
    char winner = '.';
    if (work) {
        if (board[0] == board[4] && board[4] == board[8]) {
            winner = board[0];
        }
    }
    else {
        if (board[2] == board[4] && board[4] == board[6]) {
            winner = board[2];
        }
    }
    return winner;
}

bool isValidBoard(string board) {
    int numX = 0;
    int numO = 0;
    for (char c : board) {
        if (c == 'X') {
            numX++;
        }
        else if (c == 'O') {
            numO++;
        }
        else if (c != '.') {
            return false;
        }
    }
    if (numX < numO || numX > numO + 1) {
        return false; 
    }
    return true;
}

string getWinner(string board) {
    if (!isValidBoard(board)) {
        return "Incorrect";
    }
    char winner = '.';
    for (int i = 0; i < 3; i++) {
        winner = getWinnerInRow(board.substr(i * 3, 3));
        if (winner != '.') {
            break;
        }
        winner = getWinnerInColumn(board, i);
        if (winner != '.') {
            break;
        }
    }
    if (winner == '.') {
        winner = getWinnerInDiagonal(board, true);
    }
    if (winner == '.') {
        winner = getWinnerInDiagonal(board, false);
    }
    if (winner == 'X') {
        return "Petya won";
    }
    else if (winner == 'O') {
        return "Vanya won";
    }
    else {
        return "Nobody";
    }
}

