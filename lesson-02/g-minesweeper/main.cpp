
#include <random>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// a tenyleges meret 10x10, de keretet teszunk a tombok kore, ez megakadalyozza a rossz indexelest
bool minefield[12*12]; 
bool visible[12*12];

bool alive = true;

unsigned int pos_to_index(int x, int y)
{
  // 12 - elso sor atugrasa
  // 12 elem / sor
  // +1 - bal oszlop atugrasa
  return 12 + 12*y + x + 1;
}

unsigned int mines_near(int x, int y)
{
  return 0
    + minefield[ pos_to_index(x-1, y  ) ]
    + minefield[ pos_to_index(x+1, y  ) ]
    + minefield[ pos_to_index(x-1, y+1) ]
    + minefield[ pos_to_index(x  , y+1) ]
    + minefield[ pos_to_index(x+1, y+1) ]
    + minefield[ pos_to_index(x-1, y-1) ]
    + minefield[ pos_to_index(x  , y-1) ]
    + minefield[ pos_to_index(x+1, y-1) ]
    ;
}

void handleEvents(sf::RenderWindow& window)
{
  sf::Event event;
  while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      window.close();
    }
    if (alive && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
      int x = floor((event.mouseButton.x - 5) / 50.0);
      int y = floor((event.mouseButton.y - 5) / 50.0);
      if (x >= 0 && y >= 0 && x < 10 && y < 10)
      {
        int idx = pos_to_index(x,y);

        visible[idx] = true;

        alive = !minefield[idx];
      }
    }
  }
}

int main()
{
  {
    // inicializaljuk veletlenszamokkal az aknamezot
    // egy mezo 10% esellyel akna
    std::random_device random_device;
    std::mt19937 random_generator(random_device());
    std::uniform_int_distribution<> random_distribution(1, 100);

    for (int iy=0;iy<10;++iy)
    {
      for (int ix=0;ix<10;++ix)
      {
        int idx = pos_to_index(ix, iy);
        minefield[idx] = random_distribution(random_generator) <= 10;
      }
    }

  }

  sf::RenderWindow window(sf::VideoMode(500, 500), "Hello world!");
  window.setFramerateLimit(60);

  sf::Font font;

  if(!font.loadFromFile("fonts/Roboto-Bold.ttf"))
  {
    std::cerr << "Nem talalhato a betutipus!" << std::endl;
    return 1;
  }
  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(24); // 24 pixels
  text.setColor(sf::Color::Black);
  text.setStyle(sf::Text::Bold);


  sf::RectangleShape tile(sf::Vector2f(40, 40));

  while (window.isOpen())
  {
    handleEvents(window);

    window.clear(sf::Color::Black);
    for (int iy=0;iy<10;++iy)
    {
      for (int ix=0;ix<10;++ix)
      {
        tile.setPosition(sf::Vector2f(5 + ix * 50, 5 + iy * 50));
        int idx = pos_to_index(ix, iy);
        if (visible[idx])
        {
          if (minefield[idx])
          {
            tile.setFillColor(sf::Color::Red);
          } else
          {
            tile.setFillColor(sf::Color::Green);
          }
        } else
        {
          tile.setFillColor(sf::Color::Yellow);
        }
        window.draw(tile);

        // hany bomba van a kozelben?
        if (visible[idx])
        {
          text.setString(std::to_string(mines_near(ix,iy)));

          // [fancy] igazitsuk szepen kozepre a szoveget, azzal, hogy a pozicionalasi pontjat kozepre tesszuk
          sf::FloatRect textRect = text.getLocalBounds();
          text.setOrigin(textRect.left + textRect.width/2.0f,
              textRect.top  + textRect.height/2.0f);

          text.setPosition(sf::Vector2f(25 + ix * 50, 25 + iy * 50));
          window.draw(text);
        }
      }
    }
    window.display();
  }

  return 0;
}
