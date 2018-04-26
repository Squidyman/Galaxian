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
#include "FallingStars.h"
#include "Lasers.h"
#include "Shot.h"
const int NUM_BAD_GUYS = 12;
const int STARS = 1000;

/*
git add . #adds all of the files
git commit -m "add your commit message here" #adds the files into a bundle
git push origin master #pushes the code up to github.com
*/

void Game()
{
	int count = 0;
	int firingtime = 0;
	int firingtime_step = 1000;

	Surface surface(W, H);
	Event event;
	Image SpaceShuttle = "images/galaxian/X_Wing_Fighter.png";
	Image Badguyimage_a = "images/galaxian/TIE_Fighter_small.png";
	Image Badguyimage_b = "images/galaxian/Death_Star.png";
	Image Badguyimage_c = "images/galaxian/GalaxianPurpleAlien.gif";


	Ship Player (W / 2 - 60, H / 2 + 360, surface, SpaceShuttle, W, H);
	Fleet Badguy_ships (surface, Badguyimage_a, NUM_BAD_GUYS, W, H);
	FallingStars Stars (surface, W, H, STARS);
	Lasers laser (surface, W, H);

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

		if (keypressed[SPACE])
			{
			int current_time = getTicks();
			if (current_time - firingtime > firingtime_step)
				{
					firingtime = current_time;
					int y_value = 1050;
					int x_value = Player.get_x();
					laser.create(x_value, y_value);
				}
			}
		Badguy_ships.move(laser.get_size());
		Stars.move();


		surface.lock();
		surface.fill(BLACK);
		laser.draw();
		Stars.draw();
		Player.draw();
		Badguy_ships.draw();

		surface.unlock();
		surface.flip();
		//delay(5); // this seems to be unnecessary on my computer, only adds lag
	}
	return;
}

int main(int argc, char* argv[])
{
	Game();
	return 0;
}
