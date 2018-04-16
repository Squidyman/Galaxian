#include <vector>

#include "Includes.h"
#include "Surface.h"
#include "Event.h"
#include "Rect.h"
#include "Star.h"


int Star::get_y()
{return y_;}

void Star::set_y(int y)
{
  y_ = y;
}

void Star::move()
{
  int speed = 1;
  if (y_ > 1280)
  {
    y_ = 0;
  }
  y_  += speed;

}

void Star::draw()
{
    surface_.put_rect(x_, y_, w_, h_, rand() % 256, rand() % 256 , rand() % 256);
}
