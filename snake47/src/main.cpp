
#include "../include/home_screen.hpp"
#include "../include/snake_game.hpp"
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(1200, 720), "Snake Game");

  HomeScreen homeScreen;
  SnakeGame snakeGame;

  bool inHomeScreen = true;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      if (inHomeScreen && event.type == sf::Event::KeyPressed &&
          event.key.code == sf::Keyboard::Enter) {
        inHomeScreen = false;
        window.close();
        snakeGame.init_game();
      }
    }

    window.clear();
    if (inHomeScreen) {
      homeScreen.displayHome(window);
    }
    window.display();
  }

  return 0;
}
