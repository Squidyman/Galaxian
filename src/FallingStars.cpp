
#include <vector>

#include "Image.h"
#include "Includes.h"
#include "Surface.h"
#include "Event.h"
#include "FallingStars.h"

void FallingStars::move()
{
  for (int i = 0; i < stars.size(); ++i)
  {
    stars[i].move();
  }
}

void FallingStars::draw()
{
for (int i = 0; i < stars.size(); ++i)
{
  stars[i].draw();
}
}
