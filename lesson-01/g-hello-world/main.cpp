
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


// az ablakod esemenyeit kezelo fuggveny
// billentyuzet, eger, es minden egyeb.
// ez itt most csak arra reagal, hogy ha be akarod zarni az ablakot
void handleEvents(sf::RenderWindow& window)
{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				// a while ciklusunk addig meg, amig az ablak nyitva van
				// szoval ha bezarjuk, utana a kovetkezo ellenorzesnel leall
				window.close();
			}
		}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Hello world!");
	window.setFramerateLimit(60);

	sf::Font font;

	// a program a "bin" konyvtarban van, a fontok mellette a "font" konyvtarban
	// szoval egymashoz kepest relativan ../fonts/...
	// de a relativ eleresi utak a futtatas helyetol szamitanak, nm a programetol!
	// szoval ha azt irod be, hogy ./bin/g-hello-world, akkor ez pont mukodni fog
	// ha a bin konyvtarbol futtatod, ezen modositani kell
	// kesobbi peldakban majd megnezzuk ez hogyan feloldhato
	if(!font.loadFromFile("fonts/Roboto-Bold.ttf"))
	{
		std::cerr << "Nem talalhato a betutipus!" << std::endl;
	}

	sf::Text text;
	text.setFont(font);
	text.setString("Hello world");
	text.setCharacterSize(24); // 24 pixels
	text.setColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	text.setPosition(sf::Vector2f(250, 250));

	while (window.isOpen())
	{
		handleEvents(window);

		window.clear(sf::Color::Black);

		text.rotate(2);	// setRotate, es rotate - elobbi fixen beallitja, utobbi pedig tovabb forgatja annyival

		window.draw(text);

		window.display();
	}

	return 0;
}
