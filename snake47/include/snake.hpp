#ifndef SNAKE_H
#define SNAKE_H

#include <string>

class Snake {
private:
  int x;
  int y;
  int count;

public:
  static int num_pixels;
  static std::string dir;
  // constructor
  Snake();
  // destructor
  ~Snake();
  // getCoordinates!
  int getX();
  int getY();
  int getNumPixels();
  void snake_pos(int x, int y);
};

#endif // !SNAKE_H
