#ifndef SHOT_H
#define SHOT_H
#include <vector>
#include "Includes.h"
#include "Rect.h"
#include "Surface.h"
#include "Event.h"
#include <iostream>

class Shot
{
private:
  int x_, y_;
  bool type_;
  Surface & surface_;
  Rect laser;
public:
  Shot(int x, int y, Surface & surface, bool type)
  :x_(x), y_(y), surface_(surface), type_(type)
  {
    laser.x = x_;
    laser.y = y_;
    laser.w = 5;
    laser.h = 20;
  }
void create(int, int);
void draw();
int get_x();
int get_y();
int get_w();
int get_h();
};
#endif
