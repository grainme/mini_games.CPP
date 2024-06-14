#include "../include/home_screen.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

void HomeScreen::displayHome(sf::RenderWindow &window) {
  const int h = 18;
  const int w = 30;
  const int size = 40;
  int height = h * size;
  int width = w * size;

  sf::Font font;
  if (!font.loadFromFile("../public/fonts/arcade.TTF")) {
    std::cerr << "Font Error: could not load the font" << std::endl;
    return;
  }

  sf::Text title("GAME ON", font);
  title.setCharacterSize(80);
  title.setFillColor(sf::Color::White);

  sf::Texture t1;
  if (!t1.loadFromFile("../public/images/snake.png")) {
    std::cerr << "Image Error: Could not load the image" << std::endl;
    return;
  }

  sf::Sprite sprite(t1);
  sprite.setScale(350.f / sprite.getTexture()->getSize().x,
                  350.f / sprite.getTexture()->getSize().y);

  sf::Text startText("Press ENTER to Start", font);
  startText.setCharacterSize(40);
  startText.setFillColor(sf::Color::White);

  sf::FloatRect textBounds = title.getLocalBounds();
  title.setOrigin(textBounds.width / 2, textBounds.height / 2);
  title.setPosition(width / 2, height / 8);

  sf::FloatRect spriteBounds = sprite.getLocalBounds();
  sprite.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);
  sprite.setPosition(width / 2, height / 2);

  sf::FloatRect startBounds = startText.getLocalBounds();
  startText.setOrigin(startBounds.width / 2, startBounds.height / 2);
  startText.setPosition(width / 2, height * 7 / 8);

  sf::Clock clock;
  bool showStartText = true;

  // Draw home screen
  if (clock.getElapsedTime().asSeconds() > 0.5f) {
    showStartText = !showStartText;
    clock.restart();
  }

  window.clear(sf::Color::Black);
  window.draw(title);
  window.draw(sprite);
  if (showStartText) {
    window.draw(startText);
  }
}
