//Matthew Barnard
#include <vector>
#include "Image.h"
#include "Includes.h"
#include "Rect.h"
#include "Surface.h"
#include "Event.h"
#include "Fleet.h"
#include <iostream>


void Badguy::move(bool moveLeftRight, bool dive)
{
  if (moveLeftRight == true)
  {
    myrect.x += Fleet::speed;
  }
  if (dive == true)
  {
    --myrect.y;
  }
}

void Badguy::draw()
{
  surface_.put_image(image_, myrect);
}

int Badguy::get_x() {return myrect.x;}
int Badguy::get_y() {return myrect.y;}
int Badguy::get_w() {return myrect.w;}
int Badguy::get_h() {return myrect.h;}


/*
control

bad NUM_BAD_GUYS
bad guy gets moved
flips speed when boarder is struck
bad guy reports when on boarder
*/
