//Matthew Barnard
#include <vector>
#include "Image.h"
#include "Includes.h"
#include "Rect.h"
#include "Surface.h"
#include "Event.h"
#include "Fleet.h"
#include <iostream>

bool Badguy::move(int speed, bool direction)
{
    bool piece = false;
    myrect.x += speed;
    if (myrect.x > 1910 || myrect.x < 10)
    {
      piece = true;
    }
    return piece;
}

void Badguy::draw()
{
  surface_.put_image(image_, myrect);
}

/*
control

bad NUM_BAD_GUYS
bad guy gets moved
flips speed when boarder is struck
bad guy reports when on boarder
*/
