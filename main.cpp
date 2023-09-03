#include <iostream>

#include <SFML/Graphics.hpp>

#include "Bird.hpp"
#include "Pipes.hpp"


const int SCREEN_WIDTH = 426;
const int SCREEN_HEIGHT = 640;

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird", sf::Style::Close);
	window.setFramerateLimit(60);

	Bird bird(window);
	Pipes pipes(window);

	float pipe_spawn_timer = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape)
						window.close();
					break;
				default:
					break;
			}
		}
		// Update

		pipe_spawn_timer++;
		if (pipe_spawn_timer >= 100)
		{
			pipes.Spawn(window);
			pipe_spawn_timer = 0.0f;
		}

		bird.Update(window);

		if (bird.alive)
			pipes.Update(window);

		// Render
		window.clear(sf::Color(83, 145, 245));

		bird.Render(window);
		pipes.Render(window);

		window.display();
	}

	return 0;
}