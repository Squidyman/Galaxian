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
#include "collision.h"
const int NUM_BAD_GUYS_A = 10;
const int NUM_BAD_GUYS_B = 8;
const int NUM_BAD_GUYS_C = 6;
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
	Image Badguyimage_b = "images/galaxian/TIE_Fighter_small_red.png";
	Image Badguyimage_c = "images/galaxian/TIE_Fighter_small_blue.png";

	Sound sound("sounds/PewByEvan.wav");

	int X = 30, X1 = 150, X2 = 270;
	int Y = 100, Y1 = 220, Y2 = 340;

	Ship Player (W / 2 - 60, H / 2 + 360, surface, SpaceShuttle, W, H);
	Fleet Badguy_Fleet_A (surface, Badguyimage_a, NUM_BAD_GUYS_A, W, H, X, Y);
	Fleet Badguy_Fleet_B (surface, Badguyimage_b, NUM_BAD_GUYS_B, W, H, X1, Y1);
	Fleet Badguy_Fleet_C (surface, Badguyimage_c, NUM_BAD_GUYS_C, W, H, X2, Y2);
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
					sound.play();
					firingtime = current_time;
					int y_value = 1050;
					int x_value = Player.get_x();
					laser.create(x_value, y_value);
				}
			}

		for (int j = 0; j < laser.get_size(); ++j)
		{
			for (int i = 0; i < Badguy_Fleet_A.get_size(); ++i)
			{
				if ((Badguy_Fleet_A.if_badguy_alive(i) && laser.if_alive(j)) == true)
				{
					if ((Badguy_Fleet_A.badguy_return_x(i) < laser.laser_get_x(j) + laser.laser_get_w(j) &&
	   			Badguy_Fleet_A.badguy_return_x(i) + Badguy_Fleet_A.badguy_return_w(i) > laser.laser_get_x(j) &&
	   			Badguy_Fleet_A.badguy_return_y(i) < laser.laser_get_y(j) + laser.laser_get_h(j) &&
	   			Badguy_Fleet_A.badguy_return_h(i) + Badguy_Fleet_A.badguy_return_y(i) > laser.laser_get_y(j)) == true)
					{
						laser.remove_laser(j);
						Badguy_Fleet_A.dead_badguy(i);
					}
				}
			}
			for (int i = 0; i < Badguy_Fleet_B.get_size(); ++i)
			{
				if ((Badguy_Fleet_B.if_badguy_alive(i) && laser.if_alive(j)) == true )
				{
					if (Badguy_Fleet_B.badguy_return_x(i) < laser.laser_get_x(j) + laser.laser_get_w(j) &&
	   			Badguy_Fleet_B.badguy_return_x(i) + Badguy_Fleet_B.badguy_return_w(i) > laser.laser_get_x(j) &&
	   			Badguy_Fleet_B.badguy_return_y(i) < laser.laser_get_y(j) + laser.laser_get_h(j) &&
	   			Badguy_Fleet_B.badguy_return_h(i) + Badguy_Fleet_B.badguy_return_y(i) > laser.laser_get_y(j))
					{
						Badguy_Fleet_B.dead_badguy(i);
						laser.remove_laser(j);
					}
				}
			}
			for (int i = 0; i < Badguy_Fleet_C.get_size(); ++i)
			{
				if ((Badguy_Fleet_C.if_badguy_alive(i) && laser.if_alive(j)) == true)
				{
					if (Badguy_Fleet_C.badguy_return_x(i) < laser.laser_get_x(j) + laser.laser_get_w(j) &&
					Badguy_Fleet_C.badguy_return_x(i) + Badguy_Fleet_C.badguy_return_w(i) > laser.laser_get_x(j) &&
					Badguy_Fleet_C.badguy_return_y(i) < laser.laser_get_y(j) + laser.laser_get_h(j) &&
					Badguy_Fleet_C.badguy_return_h(i) + Badguy_Fleet_C.badguy_return_y(i) > laser.laser_get_y(j))
					{
						Badguy_Fleet_C.dead_badguy(i);
						laser.remove_laser(j);
					}
				}
			}
		}
		Badguy_Fleet_A.move(laser.get_size(), Player.get_x(), Player.get_y());
		Badguy_Fleet_B.move(laser.get_size(), Player.get_x(), Player.get_y());
		Badguy_Fleet_C.move(laser.get_size(), Player.get_x(), Player.get_y());

		Stars.move();
		surface.lock();

		surface.fill(BLACK);
		laser.draw();
		Stars.draw();
		Player.draw();
		Badguy_Fleet_A.draw();
		Badguy_Fleet_B.draw();
		Badguy_Fleet_C.draw();

		surface.unlock();
		surface.flip();
	}
	return;
}
int main(int argc, char* argv[])
{
	Game();
	return 0;
}
