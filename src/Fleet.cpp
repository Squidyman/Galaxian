//Matthew Barnard
#include "Fleet.h"
#include "Surface.h"
#include "Event.h"
#include "Includes.h"
#include "Image.h"
#include <iostream>
#include <vector>

/*
also going to incorportate "suicidal" aliens in this function

Things suicide bot A, B, C needs
-X coordinate of my Ship
-width and heigth of screen

suicide bot gets chosen by:
random timer going through game;

suicide bot A will
randomly get chosen from first row of badguys
retain X value and decrease Y value, jumping up
at at the apex it get the X value of ME



*/

void Fleet::decision()
{
  int k = 5;
  int x = 60;
  int y = 80;
  move();
  dive(k, x, y);
}

void Fleet::dive(int k, int x, int y)
{
  badguy[k].dive(x, y);
}

int Fleet::speed = 5;

void Fleet::move()
{
  bool check = false;
  for (int i = 0; i < badguy.size(); ++i)
  {
    if (badguy[i].get_x() > W - 20)
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
    badguy[i].move();
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
