#pragma once

#include <iostream>
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>

#include "RandomGenerator.hpp"



class Pipes
{
	private:
		sf::RectangleShape top_pipe;
		sf::RectangleShape bottom_pipe;
		sf::RectangleShape gap;

		sf::Texture pipe_texture;

		RandomGenerator random;


	public:
		std::vector<sf::RectangleShape> pipes_vector;
		std::vector<sf::RectangleShape> gaps_vector;

		Pipes(sf::RenderWindow& i_window);
		~Pipes();

		void Move(sf::RectangleShape& body, float i_x, float i_y);
		void Draw(sf::RenderWindow& i_window, sf::RectangleShape& i_body);
		void Spawn(sf::RenderWindow& i_window);
		void Update(sf::RenderWindow& i_window);
		void Render(sf::RenderWindow& i_window);
};