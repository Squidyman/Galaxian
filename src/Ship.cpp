//Matthew Barnard
#include "Ship.h"
#include "Surface.h"
#include "Event.h"
#include "Includes.h"
#include "Image.h"
#include <iostream>

void Ship::move(bool moveLeft, bool moveRight)
{
  int dx = speed;
  if (moveLeft == true)
  {
    myrect.x -= 10;
    if (myrect.x < 2)
    {
      myrect.x = 3;
    }
  }
  else if (moveRight == true)
  {
    myrect.x += 10;
    if (myrect.x > 1790)
    {
      myrect.x = 1789;
    }
  }
}
void Ship::draw()
{
  surface_.put_image(image_, myrect);
}
