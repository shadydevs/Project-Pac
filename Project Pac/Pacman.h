#include <iostream>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Pellet.cpp"
#include "Character.h"
using namespace sf;
using namespace std;

class Pacman : public Character
{
private:
	Sprite pacman;
	int score, lives;
public:
	Pacman();
	int eatenGhosts, eatenPellets;
	
	int getScore();
	void updateScore();
	int getLives();
	void updateLives();

	Sprite getPacmanSprite();
	//void movePacman(char direction, int array[][]);
	//void eat(ghost g);
	//void eat(pellet pell);
};