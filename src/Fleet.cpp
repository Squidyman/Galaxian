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
  //check if fleet should move left/rightbutton
  // change speed accordingly
  int speed = 10;
  for (int i = 0; i < badguy.size(); ++i)
  {
    if (badguy[i].move(true))
    {
    speed = -speed;
    }
    badguy[i].move(speed);
    std::cout << speed;

  }
}


void Fleet::draw()
{
  for (int i = 0; i < badguy.size(); ++i)
  {
    badguy[i].draw();
  }
}

// form of object composition ordered association
