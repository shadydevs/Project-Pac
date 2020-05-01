#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Maze.h"
#include "Pacman.h"
#include "Animation.h"
#include "Character.h"
using namespace sf;
using namespace std;

//int collide(pacman pac, ghost ghostsArr[]) {
//    for (int i = 0; i < 4; i++)
//    {
//        if (intersects(pac.getGlobalBounds(), ghostsArr[i].getGlobalBounds)) {
//            if (pac.superModeOn()) {
//                return 1;
//            }
//            else
//            {
//                return 2;
//            }
//        }
//    }
//
//    return 0;
//}

//int collide(pacman pac, pellet pels[]) {                // think about pellets and stuff
//    for (int i = 0; i < 4; i++)
//    {
//        if (intersects(pac.getGlobalBounds(), pels[i].getGlobalBounds))
//        {
//
//        }
//    }
//
//    return 0;
//}

int main()
{
    RenderWindow window(VideoMode(600, 750), "PACMAN", Style::Close);
    window.setFramerateLimit(60);

    RectangleShape pac(Vector2f(25.0f, 25.5f));
    pac.setPosition(292.0f, 527.0f);
    Texture Tpac;
    Tpac.loadFromFile("data/pacman.png");
    pac.setTexture(&Tpac);
    
    Animation animation(&Tpac, Vector2u(3, 4), 0.3f);
    int row = 0;
    float deltaTime = 0.0f;
    Clock clock;

    //ghost ghostsArr[4];

    //Player player;
    //ofstream playersInfo;

    //cout << "enter player name: ";
    //cin >> player.name;


    
    //reading the map from file
    ifstream readMaze("data/maze2.txt");
    int maze[21][19];
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 19; j++) {
            
            readMaze >> maze[i][j];
        }
    }

    //diplaying map

    RectangleShape tile[21][19];
    CircleShape pellet[21][19];
    Texture tileT;
    tileT.loadFromFile("data/tile.png");

    float xposBoard = 0.0, yposBoard = 90.0;
    float xposDot = 0.0, yposDot = 0.0;

    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            tile[i][j].setPosition(xposBoard, yposBoard);
            tile[i][j].setSize(Vector2f(31, 28));
            pellet[i][j].setPosition(xposDot, yposDot);
            pellet[i][j].setRadius(3);

            if (maze[i][j] == -1)
            {
                tile[i][j].setTexture(&tileT);
            }
            else if (maze[i][j] == 1)
            {
                pellet[i][j].setFillColor(Color(220, 171, 187));
            }
            xposBoard += 32;
            xposDot = xposBoard + 15;
        }

        yposBoard += 29;
        yposDot = yposBoard + 14.3;
        xposBoard = 0, xposDot = 0;
    }

    //pac.setPosition();


    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == Event::Closed)
                window.close();

            if (Keyboard::isKeyPressed(Keyboard::Space))
            {
                cout << pac.getPosition().x << endl << pac.getPosition().y << endl << "----------" << endl;
            }

        }

        //pac.move();



        //if (collide(pac, ghostsArr) == 1) {
        //    pac.eat(ghost);
        //}
        //else if (collide(pac, ghostsArr) == 2) {
        //    ghost.eat(pac);
        //}

        //if (pac.isDead()) {
        //    /*
        //    end of game code {
        //        update score leaderboard
        //        cout gameover
        //        save to file
        //        ask if want to replay
        //    }
        //    */
        //}

        animation.Update(row, deltaTime);
        pac.setTextureRect(animation.uvRect);

        window.clear();
        window.draw(pac);
        for (int i = 0; i < 19; i++)
        {
            for (int j = 0; j < 21; j++)
            {
                if (maze[i][j] == -1)
                {
                    window.draw(tile[i][j]);
                }
                if (maze[i][j] == 1)
                {
                    window.draw(pellet[i][j]);
                }
            }
        }
        window.display();
    }

    return 0;
}