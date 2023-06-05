#include <iostream>

#include "Player.h"



Player::Player(std::string Name) {
	_name = Name;

}

void Player::setSymbol(int Symbol) {
	_symbol = Symbol;
	if (_symbol == 1) {
		_mark = 'X';
	}
	else if (_symbol == 2) {
		_mark = 'O';
	}
}

int Player::getSymbol() {
	return _symbol;
}

void Player::setName(std::string Name) {
	_name = Name;
}

std::string Player::getName() {
	return _name;
}

void Player::setScoreVSP(int Score) {
	_scoreVSP = Score;
}

int Player::getScoreVSP() {
	return _scoreVSP;
}

void Player::setScoreVSC(int Score) {
	_scoreVSC = Score;
}

int Player::getScoreVSC() {
	return _scoreVSC;
}

std::string Player::playerInfo() {
	return _name + " (" + _mark + ")";

}
