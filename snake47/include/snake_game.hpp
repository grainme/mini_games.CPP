#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>

class SnakeGame {
private:
  const int W = 75;
  const int H = 45;
  const int SIZE = 16;
  const int WIDTH = SIZE * W;
  const int HEIGHT = SIZE * H;
  const int TOP_BAR_HEIGHT = 50;
  int score = 0;
  int speed = 1;
  int record = 0;
  sf::Font font;
  sf::Text scoreText;
  sf::Text timeText;
  sf::Text speedText;
  sf::Text recordText;
  sf::Clock gameClock;

public:
  void init_game();
  void loop_game(sf::RenderWindow &window, std::vector<sf::Sprite> &sprites);
  void tick();
  void updateScore();
  void updateTime();
  void updateSpeed();
  void updateRecord();
};

#endif // SNAKE_GAME_HPP
