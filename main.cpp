#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"
#include "Ship.h"
#include "Fleet.h"
#include "Badguy.h"
#include "FallingStars.h"
const int NUM_BAD_GUYS = 30;

/*
git add . #adds all of the files
git commit -m "add your commit message here" #adds the files into a bundle
git push origin master #pushes the code up to github.com
*/

void Game()
{
	Surface surface(W, H);
	Event event;
	Image SpaceShuttle = "images/galaxian/SpaceShuttle.gif";
	Image Badguyimage_a = "images/galaxian/GalaxianAquaAlien.gif";
	Image Badguyimage_b = "images/galaxian/GalaxianRedAlien.gif";
	Image Badguyimage_c = "images/galaxian/GalaxianPurpleAlien.gif";


	Ship Player (W / 2 - 60, H / 2 + 360, surface, SpaceShuttle, W, H);
	Fleet A (surface, Badguyimage_a, NUM_BAD_GUYS, W, H);
	FallingStars Stars (surface, W, H);

	Rect PlayerObject = SpaceShuttle.getRect();


	while (1)
	{
		if (event.poll() && event.type() == QUIT) break;

		KeyPressed keypressed = get_keypressed();
		bool moveLeft = 0, moveRight = 0;
		if (keypressed[LEFTARROW]){
			moveLeft = true;
			Player.move(moveLeft, moveRight);
		}
		else if (keypressed[RIGHTARROW]){
			moveRight = true;
			Player.move(moveLeft, moveRight);
		}
		A.move();//idk why here


		surface.lock();
		surface.fill(BLACK);

		Stars.move();
		Stars.draw();

		Player.draw();
		A.draw();
		surface.unlock();
		surface.flip();
		delay(10);
	}
	return;
}

int main(int argc, char* argv[])
{
	Game();
	return 0;
}
