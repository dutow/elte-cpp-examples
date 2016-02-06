
#include <random>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void handleEvents(sf::RenderWindow& window)
{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
}

int main()
{
	int values[100];
	
	{
		// inicializaljuk veletlenszamokkal
		std::random_device random_device;
		std::mt19937 random_generator(random_device());
		std::uniform_int_distribution<> random_distribution(10, 100);

		for(int i=0;i<100;i++)
		{
			values[i] = random_distribution(random_generator);
		}

	}

	sf::RenderWindow window(sf::VideoMode(500, 500), "Hello world!");
	window.setFramerateLimit(60);

	sf::RectangleShape column(sf::Vector2f(4, 4));

	for (int begin=0;begin<100;++begin)
	{
		int min = begin;
		for(int i=begin;i<100;++i)
		{
			if(values[i] < values[min])
			{
				min = i;
			}

			if (!window.isOpen()) break;
			handleEvents(window);

			window.clear(sf::Color::Black);
			for(int d=0;d<100;++d)
			{
				int height = values[d] * 4;
				column.setPosition(sf::Vector2f(50+d*4, 450-height));
				column.setSize(sf::Vector2f(4, height)); 
				column.setFillColor(sf::Color::White);
				if (d == i) column.setFillColor(sf::Color::Yellow);
				if (d == min) column.setFillColor(sf::Color::Magenta);
				if (d == begin) column.setFillColor(sf::Color::Blue);
				window.draw(column);
			}

			window.display();

		}

		std::swap(values[begin], values[min]);
	}

		//window.draw(ball);

	return 0;
}
