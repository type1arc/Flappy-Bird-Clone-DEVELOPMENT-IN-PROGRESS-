#include "Bird.hpp"

Bird::Bird(sf::RenderWindow& i_window)
{

	pipes = new Pipes(i_window);

	bird.setSize(sf::Vector2f(32.0f, 32.0f));
	bird.setOrigin(bird.getSize().x / 2, bird.getSize().y / 2);
	bird.setPosition(i_window.getSize().x / 2, i_window.getSize().y / 2);

	bird_texture.loadFromFile("textures/bird.png");
	bird.setTexture(&bird_texture);
}

bool Bird::get_alive()
{
	return alive;
}

Bird::~Bird()
{
	
}

void Bird::Update(sf::RenderWindow& i_window)
{
	velocity.y += gravity;

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && (bird.getPosition().y > 0) && (bird.getPosition().y < i_window.getSize().y) && (alive) && (velocity.y > 0))
		velocity.y = -flap_speed;
	
	if (bird.getPosition().y > i_window.getSize().y)
		alive = false;

	for (auto& x : pipes->pipes_vector)
	{
		if (bird.getGlobalBounds().intersects(x.getGlobalBounds()))
		{
			alive = false;

			velocity.y = 0;
		}
	}

	bird.move(velocity);

}

void Bird::Render(sf::RenderWindow& i_window)
{
	i_window.draw(bird);
}
