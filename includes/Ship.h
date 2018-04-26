#ifndef SHIP_H
#define SHIP_H

#include "Image.h"
//#include "gameobjects.h"
#include "Includes.h"
#include "Rect.h"
#include "Surface.h"
#include "Event.h"


class Ship
{
private:
  int x_, y_, W, H;
  Rect myrect;
  Image & image_;
  Surface & surface_;
  int speed;
  bool moveLeft;
public:
  Ship(int x, int y, Surface & surface, Image & player, int W, int H)
  :x_(x), y_(y), surface_(surface), image_(player), W(W), H(H),moveLeft(true), speed(3)
  {
    myrect = image_.getRect();
    myrect.x = x_;
    myrect.y = y_;
  }

  int get_x();
  int get_y();
  void move(bool moveLeft, bool moveRight);
  void draw();
};

#endif
