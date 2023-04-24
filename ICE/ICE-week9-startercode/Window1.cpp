#include "Shape.h"

// define window class
class Window : public Rectangle
{
public:
  // Upper left (x1, y1), lower right (x2, y2)
  Window(int x1, int y1, int x2, int y2) : Rectangle(x2 - x1, y2 - y1) {}
  double GetDisplayArea() const
  {
    return GetArea();
  }

  // other stuff: drawing, etc
  // skipped: no implementation for now
};
