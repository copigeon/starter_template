
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
	delete character;
	delete passport;
	delete [] passports;
	delete [] animals;
}

bool Game::init()
{
	character = new sf::Sprite;
	passport = new sf::Sprite;

	if (!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png"))
	{
		std::cout << "background texture did not load \n";
	}
	background.setTexture(background_texture);

	//for (int i = 0; i <= 2; i++) {
		if (!passports[0].loadFromFile("../Data/Images/Critter/moose.png"))
		{
			std::cout << "moose texture did not load \n";
		}
		if (!passports[1].loadFromFile("../Data/Images/Critter/narwhal.png"))
		{
			std::cout << "narwhal texture did not load \n";
		}
		if (!passports[2].loadFromFile("../Data/Images/Critter/penguin.png"))
		{
			std::cout << "penguin texture did not load \n";
		}

		if (!animals[0].loadFromFile("../Data/Images/Critter/moose.png"))
		{
			std::cout << "moose texture did not load \n";
		}
		if (!animals[1].loadFromFile("../Data/Images/Critter/narwhal.png"))
		{
			std::cout << "narwhal texture did not load \n";
		}
		if (!animals[2].loadFromFile("../Data/Images/Critter/penguin.png"))
		{
			std::cout << "penguin texture did not load \n";
		}
	//}

	if (!myfont.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "myfont did not load \n";
	}
	logo.setString("WOOO!");
	logo.setFont(myfont);
	logo.setCharacterSize(50);
	logo.setFillColor(sf::Color(sf::Color::Red));
	logo.setPosition((window.getSize().x / 2) - (logo.getGlobalBounds().width/2), 100);

	welcome.setString("Welcome to the game!");
	welcome.setFont(myfont);
	welcome.setCharacterSize(50);
	welcome.setFillColor(sf::Color(sf::Color::Yellow));
	welcome.setPosition((window.getSize().x / 2) - (welcome.getGlobalBounds().width/2), 100);

	play.setString("play");
	play.setFont(myfont);
	play.setCharacterSize(50);
	play.setFillColor(sf::Color(sf::Color::Yellow));
	play.setPosition((window.getSize().x / 2) - 200, 250);

	quit.setString("quit");
	quit.setFont(myfont);
	quit.setCharacterSize(50);
	quit.setFillColor(sf::Color(sf::Color::Yellow));
	quit.setPosition((window.getSize().x / 2) + 200, 250);



  return true;
}

void Game::update(float dt)
{

}

void Game::render()
{
	if (in_menu) {
		window.draw(welcome);
		window.draw(play);
		window.draw(quit);
	}
	else {
		window.draw(background);
		//window.draw(character);
		window.draw(logo);
	}
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{
	if (event.key.code == sf::Keyboard::P) { in_menu = false; }
}


