
#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();
	sf::RectangleShape rect;
	float speed;
	bool ReverseDirection;
	sf::RectangleShape playerRect;
	sf::CircleShape circ;
	bool circReverseX;
	bool circReverseY;
	float distanceToMoveCircX;
	float distanceToMoveCircY;

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
};