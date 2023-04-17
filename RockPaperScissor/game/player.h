#pragma once

#ifndef PLAYER_H

#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player {
public:
	int lastAttack;
	int score;
	int wins;
	int numOfPlayer;
	string playerName;
	Player() {};
	Player(int numOfPlayer) {
		this->numOfPlayer = numOfPlayer;
		this->wins = 0;
		this->score = 0;
		this->playerName = "Player " + to_string(this->numOfPlayer);
	}
	int attack() {
		int item;
		cin >> item;
		this->lastAttack = item;
		return item;
	}
};

#endif