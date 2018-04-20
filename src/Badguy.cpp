//Matthew Barnard
#include <vector>
#include "Image.h"
#include "Includes.h"
#include "Rect.h"
#include "Surface.h"
#include "Event.h"
#include "Fleet.h"
#include <iostream>


void Badguy::dive(int x, int y)
{
  myrect.y = y;
  myrect.x = x;
}

void Badguy::move()
{
    myrect.x += Fleet::speed;
}

void Badguy::draw()
{
  surface_.put_image(image_, myrect);
}

int Badguy::get_x()
{return myrect.x;}


/*
control

bad NUM_BAD_GUYS
bad guy gets moved
flips speed when boarder is struck
bad guy reports when on boarder
*/
