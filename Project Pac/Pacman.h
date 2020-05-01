#pragma once
#include "Character.h"
class Pacman : public Character
{
private:
	CircleShape pacman;
	int score, lives;
public:
	Pacman();
	int eatenGhosts, eatenPellets;
	int getposI();
	void setposI(int i);
	int getposJ();
	void setposJ(int j);
	int getScore();
	void updateScore();
	int getLives();
	void updateLives();
	CircleShape getPacmanSprite();
	void movePacman(char direction, int array[][]);
	//void eat(ghost g);
	//void eat(pellet pell);
};
