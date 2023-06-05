#pragma once

#include <string>

class Player {
private:
	int _symbol;
	char _mark;
	std::string _name;
	int _scoreVSP = 0;
	int _scoreVSC = 0;



public:

	Player(std::string Name);

	void setSymbol(int Value);
	int getSymbol();

	void setName(std::string Name);
	std::string getName();

	void setScoreVSP(int Score);
	int getScoreVSP();

	void setScoreVSC(int Score);
	int getScoreVSC();

	std::string playerInfo();


};

