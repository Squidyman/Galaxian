#ifndef STAR_H
#define STAR_H
#include <vector>

#include "Includes.h"
#include "Surface.h"
#include "Event.h"
#include "Rect.h"

class Star
{
private:
  int x_, y_, w_, h_;
  Surface & surface_;
public:
  Star(int x, int y, Surface & surface, int w, int h)
  :x_(x), y_(y), w_(w), h_(h), surface_(surface)
  {

  }
  int get_y();
  void set_y(int y);
void move();
void draw();
};
#endif
