#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	rect.setFillColor(sf::Color::Blue);
	rect.setSize(sf::Vector2f(30,30));
	speed = 70.f;
	playerRect.setFillColor(sf::Color::Red);
	playerRect.setSize(sf::Vector2f(30, 30));
	playerRect.setPosition(1, 1);
	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		
		if (playerRect.getPosition().x + playerRect.getGlobalBounds().width <= window->getSize().x)
		{

			playerRect.move(dt * speed, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (playerRect.getPosition().x >= 0)
		{
			playerRect.move(-speed * dt, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		
		if (playerRect.getPosition().y >= 0)
		{
			playerRect.move(0, dt * -speed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		std::cout << "Down Pressed\n";
	if (playerRect.getPosition().y + playerRect.getGlobalBounds().height <= window->getSize().y)
		{
			playerRect.move(0, dt * speed);
		}
	}
	
}

// Update game objects
void Level::update(float dt)
{
	if (rect.getPosition().x + rect.getGlobalBounds().width >= window->getSize().x)
	{
		ReverseDirection = true;
		
	}else if (rect.getPosition().x <= 0)
	{
		ReverseDirection = false;
	}
	if (ReverseDirection)
	{
		rect.move(-speed * dt, 0);
	}
	else
	{
		rect.move(speed * dt, 0);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	window->draw(playerRect);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}