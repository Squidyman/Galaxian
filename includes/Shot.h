#ifndef SHOT_H
#define SHOT_H
#include <vector>
#include "Lasers.h"
#include "Includes.h"
#include "Rect.h"
#include "Surface.h"
#include "Event.h"
#include <iostream>

class Shot
{
private:
  int x_, y_;
  Surface & surface_;
public:
  Shot(int x, int y, Surface & surface)
  :x_(x), y_(y), surface_(surface)
  {}
void create(int x_value, int shot);
void draw();
};
#endif
