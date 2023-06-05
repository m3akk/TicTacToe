#include "Board.h"
#include <string>
#include <iostream>



void Board::clearBoard() {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            _board[x][y] = NO_VAL;
        }
    }
}


char Board::getSymbol(int x, int y) {
    if (_board[x][y] == NO_VAL) {
        return _symbol[NO_VAL];
    }
    if (_board[x][y] == X_VAL) {
        return _symbol[X_VAL];
    }
    if (_board[x][y] == O_VAL) {
        return _symbol[O_VAL];
    }
}


void Board::setVal(int x, int y, int val) {
    _board[x][y] = val;
}


int Board::getVal(int x, int y) {
    return _board[x][y];
}



void Board::printBoard() {

    std::cout << "\t       |       |       " << std::endl;
    std::cout << "\t   " << getSymbol(0, 0) << "   |";
    std::cout << "   " << getSymbol(0, 1) << "   |";
    std::cout << "   " << getSymbol(0, 2) << "   " << std::endl;;
    std::cout << "\t       |       |       " << std::endl;
    std::cout << "\t-----------------------" << std::endl;
    std::cout << "\t       |       |       " << std::endl;
    std::cout << "\t   " << getSymbol(1, 0) << "   |";
    std::cout << "   " << getSymbol(1, 1) << "   |";
    std::cout << "   " << getSymbol(1, 2) << "   " << std::endl;;
    std::cout << "\t       |       |       " << std::endl;
    std::cout << "\t-----------------------" << std::endl;
    std::cout << "\t       |       |       " << std::endl;
    std::cout << "\t   " << getSymbol(2, 0) << "   |";
    std::cout << "   " << getSymbol(2, 1) << "   |";
    std::cout << "   " << getSymbol(2, 2) << "   " << std::endl;;
    std::cout << "\t       |       |       " << std::endl;

}