//Matthew Barnard
#ifndef BADGUY_H
#define BADGUY_H
#include <vector>
#include "Image.h"
#include "Includes.h"
#include "Rect.h"
#include "Surface.h"
#include "Event.h"
#include <iostream>

class Badguy
{
private:
  int x_, y_;
  Rect myrect;
  Image & image_;
  Surface & surface_;
  bool if_dive = false;
  bool if_move_left_right = true;

public:
  Badguy(int x, int y, Surface & surface, Image & Badguyimage_a)
:x_(x), y_(y), surface_(surface), image_(Badguyimage_a)
{
  myrect = Badguyimage_a.getRect();
  myrect.x = x_;
  myrect.y = y_;
}
int get_x();
int get_y();
int get_w();
int get_h();
void move(bool, bool);
void draw();
//void draw_DeathStar();
};

#endif
