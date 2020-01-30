#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	rect.setFillColor(sf::Color::Blue);
	rect.setSize(sf::Vector2f(30,30));
	speed = 70.f;
	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

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