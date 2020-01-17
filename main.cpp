#include"main.h"
#include"Individual.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 720), "Prot");
	Individual *population[100];
	int popCount = 3;
	sf::CircleShape test(100);
	sf::View view;
	float a = 300, b = 300;
	view.setCenter(a, b);
	
	test.setOrigin(100, 100);
	for (int i = 0; i < popCount; i++)
	{
		population[i] = new Individual;
	}
	srand(time(NULL));
	bool dPressed = false;
	bool aPressed = false;
	bool wPressed = false;
	bool sPressed = false;
	while (window.isOpen())
	{
		sf::Event event;
		view.setCenter(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::D:
					dPressed = true;
					break;
				case sf::Keyboard::A:
					aPressed = true;
					break;
				case sf::Keyboard::S:
					sPressed = true;
					break;
				case sf::Keyboard::W:
					wPressed = true;
					break;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::D:
					dPressed = false;
					break;
				case sf::Keyboard::A:
					aPressed = false;
					break;
				case sf::Keyboard::S:
					sPressed = false;
					break;
				case sf::Keyboard::W:
					wPressed = false;
					break;
				}
			}
		}

		if (dPressed)
		{
			//view.move(1, 0);
			a += 0.5;
		}
		if (wPressed)
		{
			//view.move(0,-1);
			b -= 0.5;
		}
		if (sPressed)
		{
			//view.move(0, 1);
			b += 0.5;
		}
		if (aPressed)
		{
			//view.move(-1, 0);
			a -= 0.5;
		}

		//window.setView(view);
		//view.setCenter(population[0]->getPosition());
		//view.move(0, 0.01);
		view.setCenter(a, b);
		window.clear();
		window.setView(view);
		for (int i = 0; i < popCount; i++)
		{
			population[i]->think();
			window.draw(*(population[i]));
		}
		window.draw(test);
		window.display();
	}

	return 0;
}