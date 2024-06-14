
#include "snake_game.hpp"
#include "snake.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include <vector>

Snake s[100];

void SnakeGame::tick() {
  // update the whole snake position
  for (size_t i = s[0].num_pixels; i > 0; i--) {
    s[i].snake_pos(s[i - 1].getX(), s[i - 1].getY());
  }

  if (s[0].dir == "UP") {
    s[0].snake_pos(s[0].getX(), s[0].getY() - 1);
  } else if (s[0].dir == "RIGHT") {
    s[0].snake_pos(s[0].getX() + 1, s[0].getY());
  } else if (s[0].dir == "LEFT") {
    s[0].snake_pos(s[0].getX() - 1, s[0].getY());
  } else if (s[0].dir == "DOWN") {
    s[0].snake_pos(s[0].getX(), s[0].getY() + 1);
  }

  if (s[0].getX() >= W)
    s[0].snake_pos(0, s[0].getY());
  if (s[0].getX() < 0)
    s[0].snake_pos(W - 1, s[0].getY());
  if (s[0].getY() >= H)
    s[0].snake_pos(s[0].getX(), 0);
  if (s[0].getY() < 0)
    s[0].snake_pos(s[0].getX(), H - 1);

  score++;
  updateScore();
}

void SnakeGame::loop_game(sf::RenderWindow &window,
                          std::vector<sf::Sprite> &sprites) {
  sf::Clock clock;
  float timer = 0, delay = 0.1;
  while (window.isOpen()) {
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    sf::Event e;
    while (window.pollEvent(e)) {
      if (e.type == sf::Event::Closed) {
        window.close();
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      s[0].dir = "LEFT";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      s[0].dir = "UP";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      s[0].dir = "RIGHT";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      s[0].dir = "DOWN";
    }

    if (timer > delay) {
      timer = 0;
      tick();
    }

    window.clear();

    for (size_t i{0}; i < W; i++) {
      for (size_t k{0}; k < H; k++) {
        sprites[0].setPosition(i * SIZE, k * SIZE + TOP_BAR_HEIGHT);
        window.draw(sprites[0]);
      }
    }

    for (size_t i = 0; i < s[0].num_pixels; i++) {
      sprites[2].setPosition(s[i].getX() * SIZE,
                             s[i].getY() * SIZE + TOP_BAR_HEIGHT);
      window.draw(sprites[2]);
    }

    updateTime();
    updateSpeed();
    updateRecord();

    window.draw(scoreText);
    window.draw(timeText);
    window.draw(speedText);
    window.draw(recordText);

    window.display();
  }
}

void SnakeGame::init_game() {
  srand(time(0));

  if (!font.loadFromFile("../public/fonts/arcade.TTF")) {
    std::cerr << "Font Error: could not load the font" << std::endl;
    return;
  }

  scoreText.setFont(font);
  scoreText.setCharacterSize(20);
  scoreText.setFillColor(sf::Color::White);
  scoreText.setPosition(10, 10);

  timeText.setFont(font);
  timeText.setCharacterSize(20);
  timeText.setFillColor(sf::Color::White);
  timeText.setPosition(200, 10);

  speedText.setFont(font);
  speedText.setCharacterSize(20);
  speedText.setFillColor(sf::Color::White);
  speedText.setPosition(400, 10);

  recordText.setFont(font);
  recordText.setCharacterSize(20);
  recordText.setFillColor(sf::Color::White);
  recordText.setPosition(600, 10);

  updateScore();
  updateTime();
  updateSpeed();
  updateRecord();

  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT + TOP_BAR_HEIGHT),
                          "Snake47");

  sf::Texture t1, t2, t3;
  if (!t1.loadFromFile("../public/images/white.png") ||
      !t2.loadFromFile("../public/images/red.png") ||
      !t3.loadFromFile("../public/images/green.png")) {
    std::cerr << "Image Error: could not load the images" << std::endl;
    return;
  }

  sf::Sprite sprite1(t1), sprite2(t2), sprite3(t3);
  std::vector<sf::Sprite> sprites = {sprite1, sprite2, sprite3};

  loop_game(window, sprites);
}

void SnakeGame::updateScore() {
  scoreText.setString("Score " + std::to_string(score));
}

void SnakeGame::updateTime() {
  int seconds = static_cast<int>(gameClock.getElapsedTime().asSeconds());
  timeText.setString("Time " + std::to_string(seconds));
}

void SnakeGame::updateSpeed() {
  speedText.setString("Speed " + std::to_string(speed));
}

void SnakeGame::updateRecord() {
  recordText.setString("Record " + std::to_string(record));
}
