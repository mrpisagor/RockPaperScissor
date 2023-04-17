#pragma once

#ifndef GAME_H

#define GAME_H

#include <iostream>
#include <iomanip>
#include <game/game.h>
#include <game/player.h>

class Game {
public:
	int MAX_END_SCORE;
	int playerCount;
	Player* players;
	Player winner;
	bool isEnd;
	Game() {
		this->MAX_END_SCORE = getScore();
		this->isEnd = false;
		playerCount = getPlayerCount();
		this->players = new Player[playerCount];
		for (int i = 0; i < playerCount; i++) {
			Player player(i + 1);
			this->players[i] = player;
		}
	}
	int getScore() {
		int endScore;
		cout << "Please enter end score: ";
		cin >> endScore;
		return endScore;


	}
	int getPlayerCount() {
		int count;
		cout << "Do you wanna how many user: ";
		cin >> count;
		return count;

	}

	void start() {
		cout << setfill('-');
		while (!isEnd) {
			cout << "[0] Rock" << endl;
			cout << "[1] Paper" << endl;
			cout << "[2] Scissor" << endl;
			for (int i = 0; i < playerCount; i++) {
				cout << "Player " << to_string(i + 1) << ": ";
				players[i].attack();
			}

			checkRaundWinner();

			cout << setw(20) << '\n';
			for (int i = 0; i < playerCount; i++) {
				cout << players[i].playerName << " Score: " << to_string(players[i].score) << endl;
			}
			cout << setw(20) << '\n';
			getchar();
		}
		cout << this->winner.playerName << " wins" << endl;
	}
	void checkEnd() {

		int count = 0;
		int winnerId;
		for (int i = 0; i < playerCount; i++) {

			if (MAX_END_SCORE == players[i].score) {
				if (count == 1) {
					MAX_END_SCORE++;
					return;
				}
				count++;
				winnerId = i;
			}

		}

		if (count == 1) {

			this->winner = players[winnerId];
			this->isEnd = true;
		}
	}
	void checkRaundWinner() {
		for (int i = 0; i < playerCount; i++) {
			for (int j = 0; j < playerCount; j++) {
				if (i != j) {
					int x = players[i].lastAttack;
					int y = players[j].lastAttack;

					int result = (2 - abs(x - y)) * (x + y + abs(x - y)) / 2;
					if (x != y) {
						if (x == result) {
							players[i].wins++;
						}
						else {
							players[j].wins++;
						}
					}
				}
			}
		}
		int max = 0;
		for (int i = 0; i < playerCount; i++) {
			if (players[i].wins > players[max].wins) {
				max = i;
			}
		}
		for (int i = 0; i < playerCount; i++) {
			if (players[i].wins == players[max].wins) {
				cout << players[i].playerName << endl;
				players[i].score++;

			}
		}
		for (int i = 0; i < playerCount; i++) {
			players[i].wins = 0;
		}
		checkEnd();
	}

};


#endif

