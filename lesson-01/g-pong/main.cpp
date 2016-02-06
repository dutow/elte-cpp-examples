
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int player1_position = 150;
int player2_position = 150;

double ball_x = 200;
double ball_y = 200;

double ball_dx = 2;
double ball_dy = 0;

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

		// elso jatekos
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if(player1_position >= 5) player1_position -= 5;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if(player1_position <= 395) player1_position += 5;
		}

		// masodik jatekos
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if(player2_position >= 5) player2_position -= 5;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if(player2_position <= 395) player2_position += 5;
		}
}

void ball_direction(int at)
{
	at -= 50; // 100 magas, 50 a kozepe

	double relative_position = at / 50.0;

	double bounce_angle = relative_position * 45;

	// a sebesseg mindig 2
	ball_dx = 2 * std::cos(bounce_angle);
	ball_dy = 2 * std::sin(bounce_angle);
	
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Hello world!");
	window.setFramerateLimit(60);

	sf::CircleShape ball(10);

	sf::RectangleShape player1(sf::Vector2f(20, 100));
	sf::RectangleShape player2(sf::Vector2f(20, 100));


	while (window.isOpen())
	{
		handleEvents(window);

		ball_x += ball_dx;
		ball_y += ball_dy;

		if (ball_x > 403 || ball_x < -3)
		{
			// vege a jateknak
			break;
		}

		if (ball_y <= 0) // visszapattanik a tetejerol
		{
			ball_y *= -1;
			ball_dy *= -1;
		}

		if (ball_y >= 400) // visszapattanik az aljarol
		{
			ball_y = 800 - ball_y;
			ball_dy *= -1;
		}

		if (ball_x <= 0 && ball_y >= player1_position && ball_y <= player1_position + 100) // utkozes az elso jatekossal
		{

			// a visszafordulas szoge attol fugg, hol talalta el
			int at = ball_y - player1_position;
			ball_direction(at);
			ball_x = 1;
			
		}

		if (ball_x >= 400 && ball_y >= player2_position && ball_y <= player2_position + 100) // utkozes a masodik jatekossal
		{
			// a visszafordulas szoge attol fugg, hol talalta el
			int at = ball_y - player2_position;
			ball_direction(at);
			ball_x = 399;
			
			// ellenkezo iranyba megyunk
			ball_dx *= -1; // visszafordulunk
		}

		ball.setPosition(sf::Vector2f(50+round(ball_x)-10, 30+round(ball_y)-10));
		player1.setPosition(sf::Vector2f(30, 30+player1_position));
		player2.setPosition(sf::Vector2f(450, 30+player2_position));

		window.clear(sf::Color::Black);

		window.draw(player1);
		window.draw(player2);
		window.draw(ball);

		window.display();
	}

	return 0;
}
