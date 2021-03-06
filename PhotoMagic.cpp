#include <iostream>
#include <cstring>
#include <cstdlib>
#include "LFSR.hpp"


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char* argv[]) {

  LFSR lfsr(string(argv[3]), atoi(argv[4]));
  sf::Image image_input;
  sf::Image image_output;
  image_input.loadFromFile(argv[1]);
  image_output.loadFromFile(argv[1]);

  sf::Color colour;  
  sf::Vector2u picSize = image_output.getSize();
  for(unsigned x = 0; x < picSize.x; x++)
    for(unsigned y = 0; y < picSize.y; y++) {
      colour = image_output.getPixel(x, y);
      colour.r = (colour.r ^ lfsr.generate(8));
      colour.g = (colour.g ^ lfsr.generate(8));
      colour.b = (colour.b ^ lfsr.generate(8));
      image_output.setPixel(x, y, colour);
    }
 
  sf::Texture texture_input;
  sf::Texture texture_output;
  texture_input.loadFromImage(image_input);
  texture_output.loadFromImage(image_output);

  sf::Sprite sprite_input;
  sf::Sprite sprite_output;
  sprite_input.setTexture(texture_input);
  sprite_output.setTexture(texture_output);

  sf::RenderWindow window_input(sf::VideoMode(picSize.x, picSize.y), "Input");
  sf::RenderWindow window_output(sf::VideoMode(picSize.x, picSize.y), "Output");

  while(window_input.isOpen() && window_output.isOpen()) {
    sf::Event event;
    while(window_input.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
	window_input.close();
    }
    while (window_output.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
	window_input.close();
    }
    
    window_input.clear(sf::Color::White);
    window_input.draw(sprite_input);
    window_input.display();
    window_output.clear(sf::Color::White);
    window_output.draw(sprite_output);
    window_output.display();
}
  return 0;
}
