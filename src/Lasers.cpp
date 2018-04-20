#include "Surface.h"
#include <vector>
#include "Includes.h"
#include "Rect.h"
#include "Surface.h"
#include "Event.h"
#include <iostream>
#include "Lasers.h"

void Lasers::create(int x, int shot)
{
int fired = 1000;
  laser_array[shot].create(x, fired);
}

void Lasers::draw()
{
  for (int i = 0; i < laser_array.size(); ++i)
  {
    laser_array[i].draw();
  }
}
