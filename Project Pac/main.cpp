#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Maze.h"
#include "Pacman.h"
#include "Animation.h"
#include "Character.h"

using namespace sf;
using namespace std;


int collide(Pacman pac, ghost ghostsArr[]) {
    for (int i = 0; i < 4; i++)
    {
        if (intersects(pac.getGlobalBounds(), ghostsArr[i].getGlobalBounds)) {
            if (pac.superModeOn()) {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }

    return 0;
}

int collide(pacman pac, pellet pels[]) {                // think about pellets and stuff
    for (int i = 0; i < 4; i++)
    {
        if (intersects(pac.getGlobalBounds(), pels[i].getGlobalBounds))
        {

        }
    }

    return 0;
}

int main()
{
    RenderWindow window(VideoMode(712.5, 950), "PACMAN", Style::Close);
    window.setFramerateLimit(60);

    
    //Animation animation(&Tpac, Vector2u(3, 4), 0.3f);
    //int row = 0;
    //float deltaTime = 0.0f;
    //Clock clock;

    ghost ghostsArr[4];

    Player player;
    ofstream playersInfo;

    cout << "enter player name: ";
    cin >> player.name;

    Pacman pac;
    Maze maze("data/maze2.txt", "data/tile.png", "data/pellet.png", pac);

    pac.setPosition();


    while (window.isOpen())
    {
        //deltaTime = clock.restart().asSeconds();

        Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == Event::Closed)
                window.close();


        }

        pac.move();



        if (collide(pac, ghostsArr) == 1) {
            pac.eat(ghost);
        }
        else if (collide(pac, ghostsArr) == 2) {
            ghost.eat(pac);
        }

        if (pac.isDead()) {
            /*
            end of game code {
                update score leaderboard
                cout gameover
                save to file
                ask if want to replay
            }
            */
        }

        //animation.Update(row, deltaTime);
        //pac.setTextureRect(animation.uvRect);

        window.clear();
        //window.draw(pac.getPacmanSprite());
        for (int i = 0; i < sizey; i++)
        {
            for (int j = 0; j < sizex; j++)
            {
                window.draw(maze.mazeSprites[i][j]);
            }
        }

        window.display();
    }

    return 0;
}