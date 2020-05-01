#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
using namespace sf;

const int sizex = 19, sizey = 21;

class Maze
{
private:
	int bitmap[sizey][sizex];
	ifstream bitmapFile;
	Pacman& pac;
	int playeri, playerj;
	Texture pelletT;
	Texture playerT;
	Texture tileT;
public:
	Maze(string, string, string, Pacman _pac);

	Sprite mazeSprites[sizey][sizex];
};

