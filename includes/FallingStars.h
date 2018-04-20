#ifndef FALLINGSTARS_H
#define FALLINGSTARS_H
#include <vector>

#include "Includes.h"
#include "Surface.h"
#include "Event.h"
#include "Rect.h"
#include "Star.h"

class FallingStars
{
private:
  std::vector<Star> stars;
  int W, H;
  Surface & surface_;
  int STARS;


public:
  FallingStars(Surface & surface, int W, int H, int STARS)
  :surface_(surface), W(W), H(H), STARS(STARS)
  {
    for (int i = 0; i < STARS; ++i)
    {
      int x = rand() % (W - 1);
      int y = rand() % (H - 1);
      int w = 2;
      int h = 2;
      Star star (x, y, surface, w, h);
      stars.push_back(star);
    }
  }
  void move();
  void draw();
};
#endif
