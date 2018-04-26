//Matthew Barnard
#include "Fleet.h"
#include "Surface.h"
#include "Event.h"
#include "Includes.h"
#include "Image.h"
#include <iostream>
#include <vector>

/*
  int current_time = getTicks();
  if (current_time  % 2000 < 15)s
  {
    int Bot_chosen_to_attack = rand() % 5;
    dive(Bot_chosen_to_attack, x, y);
  }
  */

// form of object composition ordered association


int Fleet::speed = 2;

void Fleet::move(int laser_size)
{

  bool check = false;
  for (int i = 0; i < badguy.size(); ++i)
  {
    if (badguy[i].get_x() > W - 110)
    {
      check = true;
      break;
    }
    else if (badguy[i].get_x() < 20)
    {
      check = true;
    }
  }
  if (check == true)
  {
    Fleet::speed *= -1;
  }
  for (int i = 0; i < badguy.size(); ++i)
  {
    bool moveLeftRight = true, dive = false;
    badguy[i].move(moveLeftRight, dive);
  }
}

void Fleet::draw()
{
  for (int i = 0; i < badguy.size(); ++i)
  {
    badguy[i].draw();
  }
}
