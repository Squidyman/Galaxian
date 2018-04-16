//Matthew Barnard
#include "Fleet.h"
#include "Surface.h"
#include "Event.h"
#include "Includes.h"
#include "Image.h"
#include <iostream>
#include <vector>


void Fleet::move()
{
int speed = 5;
int dx = speed;

//badguy[5].x += speed;

}


void Fleet::draw()
{
  for (int i = 0; i < badguy.size(); ++i)
  {
    badguy[i].draw();
  }
}

// form of object composition ordered association
