#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Character
{
protected:
	float speed;				//speed of movement
	Vector2i direction;			//direction of movement
	Texture t;					//texture used for shape
	int posI, posJ;				//position on bitmap

public:
	Character();
	bool detectnext();			//for detecting walls
	int getposI();
	void setposI(int i);
	int getposJ();
	void setposJ(int j);

	//virtual void eat();			//for eating pellets/ghosts/pacman (overriding)
};

