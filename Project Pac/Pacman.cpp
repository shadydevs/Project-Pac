#include "Pacman.h"

Pacman::Pacman() {
	t.loadFromFile("data/pacman-left.png");
	pacman.setTexture(t);
	//pacman.setPosition(292.0f, 527.0f);
}

//int Pacman::getScore()
//{
//	return score;
//}
//void Pacman::updateScore()
//{
//	if (score >= 10000)
//		lives++;
//}
//int Pacman::getLives()
//{
//	return lives;
//}
//void Pacman::updateLives()
//{
//	if (lives < 1)
//		// game over
//}
//void Pacman::checkPellets()
//{
//	if (eatenPellets == )
//		//you won!
//}
Sprite Pacman::getPacmanSprite()
{
	return pacman;
}
//void Pacman::movePacman(char direction, int array[][])
//{
//	switch (direction)
//		case 'L'
//		while (array[posI][posJ - 1] != -1)
//		{
//			pacman.move(-100, 0);
//			posJ--;
//		}
//	break;
//	case 'R'
//		while (array[posI][posJ + 1] != -1)
//		{
//			pacman.move(100, 0);
//			posJ++;
//		}
//	break;
//	case 'U'
//		while (array[posI - 1][posJ] != -1)
//		{
//			pacman.move(0, -100);
//			posI--;
//		}
//	break;
//	case 'D'
//		while (array[posI + 1][posJ] != -1)
//		{
//			pacman.move(0, 100);
//			posI++;
//		}
//	break;
//	default:
//		break;
//}
//void Pacman::eat(ghost g[])
//{
//	for (int i = 0; i < 4; i++)
//	{
//		if (collide(pac, g[i]) == 1) //An object of class pacman and an object of class ghost are given as parameters
//		{
//			g[i].ghost.setPosition(g[i].getstartPosition())
//
//				//if pacman is in fright mode
//				score = score + 200 * countGhosts;//200 for first, 400 for second, 800 for third, 1600 for forth
//			check_score(score);
//			countGhosts++;
//		}
//		else if (collide(pac, g[i]) == 2)
//		{
//			lives--;
//			update_lives();
//			pacman.setPosition(292, 527); // return to initial position
//		}
//
//	}
//}
//void Pacman::eat(pellet pell)
//{
//	if (collide(pac, pell) && (!pell.isEaten)) //check this
//	{
//		//I assummed that in the pellet structure, there is a boolean variable called power
//		if (pell.power == true) //object is in fright mode
//		{
//			score = score + 50;
//			updateScore();
//			//remove pellet, make it an empty space
//		}
//		else
//		{
//			score = score + 10;
//			updateScore();
//			//remove pellet, make it an empty space
//		}
//		eatenPellets++;
//		pell.isEaten = true;
//	}
//}
////int main()
////{
////	pacman pac;
////	const int rows = 10;
////	const int columns = 10;
////	int array[rows][columns];
////	Sprite maze[rows][columns];
////
////	// Create the main window
////	RenderWindow game(Videomode(800, 600), "Pacman");
////
////	//declare all of my variables that I need. Do any initializations here.
////
////
////
////	// Start the game loop -- this is where my logic happens
////	while (game.isOpen())
////	{
////		// Process events
////		Event event;
////
////		while (game.pollEvent(event))
////		{
////			//if my user pressed a button on their keyboard
////			if (event.type == Event::KeyPressed)
////			{
////				//what is the button they pressed?
////
////				switch (event.key.code)
////				{
////				case Keyboard::Escape:
////					window.close();
////					break;
////
////				case Keyboard::Left:
////					pac.movePlayer('L', array)
////						break;
////				case Keyboard::Right:
////					pac.movePlayer('R', array)
////						break;
////				case Keyboard::Up:
////					pac.movePlayer('U', array)
////						break;
////				case Keyboard::Down:
////					pac.movePlayer('D', array)
////						break;
////				default:
////					break;
////				}
////			}
////		}
////		// CLear screen
////		game.clear();
////		// Draw any of the things that I declared to the screen that I want to be visible
////		game.draw(pac.getPacmanSprite());
////		// Update the window
////		game.display();
////	}
////	return 0;
////}