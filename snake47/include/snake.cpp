#include "snake.hpp"

int Snake::num_pixels{4};
std::string Snake::dir{"RIGHT"};

Snake::Snake() { this->count = 0; }
Snake::~Snake() {
  // todo
}
// get snake position
int Snake::getX() { return this->x; }
int Snake::getY() { return this->y; }
// update snake position
void Snake::snake_pos(int x, int y) {
  this->x = x;
  this->y = y;
}
