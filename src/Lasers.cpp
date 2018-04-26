#include "Surface.h"
#include <vector>
#include "Includes.h"
#include "Rect.h"
#include "Surface.h"
#include "Event.h"
#include <iostream>
#include "Lasers.h"

void Lasers::create(int x, int y)
{
  for (int i = 0; i < 2; ++i)
  {
    laser_array[Lasers::shot_number].create(x, y);
    laser_array[Lasers::shot_number + 1].create(x + 150, y);
    if(Lasers::shot_number > 27)
      Lasers::shot_number = 0;
    Lasers::shot_number +=2;
  }
}

int Lasers::shot_number = 29;

void Lasers::draw()
{
  for (int i = 0; i < laser_array.size(); ++i)
  {
    laser_array[i].draw();
  }
}

int Lasers::get_size() {return laser_array.size();}
