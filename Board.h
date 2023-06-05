#pragma once

#include <vector>
#include <string>

const int TIE_VAL = -1;
const int NO_VAL = 0;
const int X_VAL = 1;
const int O_VAL = 2;


const char _symbol[3] = { ' ', 'X', 'O' };


class Board {
private:
	int _board[3][3];

public:
	void clearBoard();
	void printBoard();
	int getVal(int x, int y);
	void setVal(int x, int y, int val);
	char getSymbol(int x, int y);

};