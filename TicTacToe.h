#pragma once

#include "Board.h"
#include "Player.h"



class ComputerMoves {
public:

	int x;
	int y;
	int score;

	ComputerMoves() {}
	ComputerMoves(int Score) : score(Score) {}

};



class TicTacToe {
private:

	int _gameMode;
	int _currentPlayer;
	int _gameLevel;
	int _gameNumber = 1;
	int _endMenu;


	Board board;
	Player computer = Player("Computer");
	Player player1 = Player("Player1");
	Player player2 = Player("Player2");
	
	ComputerMoves getBestMove(int player, int depth = 0);


public:
	void header();
	void score();
	void setGameLevel();
	void setGameMode();
	void setPlayer();
	void setGame();
	int endGame();
	void runGame();
	void playerMove();
	void computerMove();
	void randomMove();
	void bestMove();
	void changePlayer();
	int checkVictory();
	void endScreen();
};
