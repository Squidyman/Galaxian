#include "Surface.h"
#include <vector>
#include "Includes.h"
#include "Rect.h"
#include "Surface.h"
#include "Event.h"
#include <iostream>
#include "Shot.h"

/*
Shot mechanisms
has X, Y, W, Y coordinates
input: X, Y, color

Differences of the types of shots:
Good guys shot:
  get X and Y coordinates from good guy ship
  get fire command from spacebar in main.cpp
Bad guys shot
  gets X and Y coordinates from alien ship
  gets fire command from alien ship

*/


void Shot::create(int x, int y)
{
  laser.x = x;
  laser.y = y;
}

void Shot::draw()
{
  if (laser.y > -20)
    laser.y -= 5;
  surface_.put_rect(laser.x, laser.y, laser.w, laser.h, 255, 255, 0);
}

int Shot::get_x() {return laser.x;}
int Shot::get_y() {return laser.y;}
int Shot::get_w() {return laser.w;}
int Shot::get_h() {return laser.h;}

/*
get_tick()
int firing_time = -1;

int firingtime_step = 1000;
if (spacebar[pressed])
int = set_ticks()
  if (curtime = firingtime > firing_time_step)
    current time = set_ticks();
    firing time = current time;
    fire
*/
