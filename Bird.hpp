#pragma once

#include <SFML/Graphics.hpp>

#include "Pipes.hpp"

class Bird
{
	private:
		sf::Texture bird_texture;
		sf::Vector2f BIRD_SIZE = bird.getSize();

		float gravity = 1.0f;
		float flap_speed = 10.0f;

		Pipes* pipes;


	public:
		sf::RectangleShape bird;
		sf::Vector2f velocity;

		bool alive = true;

		Bird(sf::RenderWindow& window);
		~Bird();

		bool get_alive();

		void Update(sf::RenderWindow& i_window);
		void Render(sf::RenderWindow& i_window);
};