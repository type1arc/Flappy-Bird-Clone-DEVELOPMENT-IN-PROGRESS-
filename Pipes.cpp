#include "Pipes.hpp"

Pipes::Pipes(sf::RenderWindow& i_window)
{
}

Pipes::~Pipes()
{
}

void Pipes::Move(sf::RectangleShape& i_body, float i_x, float i_y)
{
	i_body.move(i_x, i_y);
}

void Pipes::Draw(sf::RenderWindow& i_window, sf::RectangleShape& i_body)
{
	i_window.draw(i_body);
}

void Pipes::Spawn(sf::RenderWindow& i_window)
{
	

	top_pipe.setSize(sf::Vector2f(50.0f, 500.0f));
	top_pipe.setPosition(sf::Vector2f(i_window.getSize().x + 50, random.generate_random_int<int>(i_window.getSize().y / -16, i_window.getSize().y / 2)));
	top_pipe.setOrigin(top_pipe.getSize().x / 2, top_pipe.getSize().y);

	pipe_texture.loadFromFile("textures/pipe.png");
	top_pipe.setTexture(&pipe_texture);

	gap.setSize(sf::Vector2f(50.0f, 200.0f));
	gap.setPosition(sf::Vector2f(i_window.getSize().x, top_pipe.getPosition().y));
	gap.setOrigin(gap.getSize().x / 2, 0);
	gap.setFillColor(sf::Color(0, 0, 0, 0));

	bottom_pipe.setSize(sf::Vector2f(50.0f, 500.0f));
	bottom_pipe.setPosition(sf::Vector2f(i_window.getSize().x + 50, gap.getPosition().y + gap.getSize().y));
	bottom_pipe.setOrigin(bottom_pipe.getSize().x / 2, 0);

	bottom_pipe.setTexture(&pipe_texture);

	pipes_vector.push_back(top_pipe);
	pipes_vector.push_back(bottom_pipe);
	gaps_vector.push_back(gap);
}

void Pipes::Update(sf::RenderWindow& i_window)
{
	for (auto& x : pipes_vector)
	{
		x.move(-1.0f, 0.0f);

		for (size_t i = 0; i <= pipes_vector.size(); i++)
		{
			if (x.getPosition().x < -50)
				pipes_vector.erase(pipes_vector.begin() + i);
		}
	}

	for (auto& x : gaps_vector)
	{
		x.move(-1.0f, 0.0f);

		for (size_t i = 0; i <= gaps_vector.size(); i++)
		{
			if (x.getPosition().x < -50)
				gaps_vector.erase(gaps_vector.begin() + i);
		}
	}
}

void Pipes::Render(sf::RenderWindow& i_window)
{
	for (auto& x : pipes_vector)
		i_window.draw(x);

	for (auto& x : gaps_vector)
		i_window.draw(x);
}
