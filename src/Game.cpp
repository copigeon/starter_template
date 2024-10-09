
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
	if (!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png"))
	{
		std::cout << "background texture did not load \n";
	}
	background.setTexture(background_texture);

	if (!bird_texture.loadFromFile("../Data/WhackaMole Worksheet/bird.png"))
	{
		std::cout << "bird texture did not load \n";
	}
	bird.setTexture(bird_texture);
	bird.setPosition(200, 200);
	bird.setScale(0.5,0.5);

	if (!myfont.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "myfont did not load \n";
	}
	logo.setFont(myfont);
	logo.setCharacterSize(50);
	logo.setFillColor(sf::Color(sf::Color::Red));
	logo.setPosition((window.getSize().x / 2) - logo.getGlobalBounds().width, 100);
	logo.setString("WOOO!");

  return true;
}

void Game::update(float dt)
{

}

void Game::render()
{
	window.draw(background);
	window.draw(bird);
	window.draw(logo);
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{

}


