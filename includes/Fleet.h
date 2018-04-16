#ifndef FLEET_H
#define FLEET_H
#include <vector>

#include "Image.h"
#include "Includes.h"
#include "Rect.h"
#include "Surface.h"
#include "Event.h"
#include "Badguy.h"
#include <iostream>

class Fleet
{
private:
  std::vector<Badguy> badguy;
  int x_, y_, W, H;
  int NUM_BAD_GUYS;
  Rect myrect;
  Image & image_;
  Surface & surface_;
  int speed_;

public:
  Fleet(Surface & surface, Image & Badguyimage_a, int NUM_BAD_GUYS, int W, int H)
:NUM_BAD_GUYS(NUM_BAD_GUYS), surface_(surface), image_(Badguyimage_a)
  {
    int x = 30, y = 0;
    for (int i = 0; i < NUM_BAD_GUYS; ++i)
    {
    	Badguy a (x, y, surface, Badguyimage_a);
    	badguy.push_back(a);
    	x+=30;
    }
  }
  void move();
  void draw();
};

#endif
