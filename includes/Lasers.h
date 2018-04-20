#ifndef LASERS_H
#define LASERS_H
#include <vector>
#include "Includes.h"
#include "Rect.h"
#include "Surface.h"
#include "Event.h"
#include <iostream>
#include "Shot.h"
class Lasers
{
private:
  Surface & surface_;
  int W, H, shot_;
  std::vector<Shot> laser_array;
public:
  Lasers(Surface & surface, int W, int H, int shot)
  :surface_(surface), W(W), H(H), shot_(shot)
  {
    int x = 0, y = -20;
    for (int i = 0; i < 100; ++i)
    {
      Shot player_shot (x, y, surface);
      laser_array.push_back(player_shot);
    }
  }
void create(int x, int shot);
void draw();
};

/*
Array of 100 bullets is created

the spacebar is pressed:

shot counter increased by 1. Till 99 then reset to 0
X value of Player is saved
Y value is set to 1280

decreasing value of shots
Y value of all the ships is decreased unless the shot has the value of 0


*/

#endif
