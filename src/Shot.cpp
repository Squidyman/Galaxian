#include "Surface.h"
#include <vector>
#include "Includes.h"
#include "Rect.h"
#include "Surface.h"
#include "Event.h"
#include <iostream>
#include "Lasers.h"

void Shot::create(int x, int shot)
{
  x_ = x + 51;
  y_ = shot;
}

void Shot::draw()
{
  if (y_ > -20)
    y_ -= 5;
  surface_.put_rect(x_, y_, 20, 20, 100, 50, 110);
}

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
