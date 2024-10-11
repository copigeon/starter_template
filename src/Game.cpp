
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
	delete drag_offset;
}

bool Game::init()
{
	character = new sf::Sprite;
	passport = new sf::Sprite;
	drag_offset = new sf::Vector2f;

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
		if (!passports[1].loadFromFile("../Data/Images/Critter/elephant.png"))
		{
			std::cout << "elephant texture did not load \n";
		}
		if (!passports[2].loadFromFile("../Data/Images/Critter/penguin.png"))
		{
			std::cout << "penguin texture did not load \n";
		}

		if (!animals[0].loadFromFile("../Data/Images/Critter/moose passport.png"))
		{
			std::cout << "moose texture did not load \n";
		}
		if (!animals[1].loadFromFile("../Data/Images/Critter/elephant passport.png"))
		{
			std::cout << "elephant texture did not load \n";
		}
		if (!animals[2].loadFromFile("../Data/Images/Critter/penguin passport.png"))
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

	newAnimal();

  return true;
}

void Game::update(float dt)
{
	dragSprite(dragged, *drag_offset);
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
		window.draw(*character);
		window.draw(*passport);
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

void Game::mouseButtonPressed(sf::Event event)
{
	if (event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2f click = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		if (passport->getGlobalBounds().contains(click))
		{
			drag_offset->x = click.x - passport->getPosition().x;
			drag_offset->y = click.y - passport->getPosition().y;
			dragged = passport;
		}
	}
}

void Game::mouseButtonReleased(sf::Event event)
{
	dragged = nullptr;
}

void Game::newAnimal()
{
	passport_accepted = false;
	passport_rejected = false;

	int animal_index = rand() % 3;
	int passport_index = rand() % 3;

	if (animal_index == passport_index) {
		should_accept = true;
	}
	else {
		should_accept = false;
	}

	character->setTexture(animals[animal_index], true);
	character->setScale(0.6, 0.6);
	character->setPosition(window.getSize().x / 12, window.getSize().y / 12);

	passport->setTexture(passports[passport_index]);
	passport->setScale(1.8, 1.8);
	passport->setPosition(window.getSize().x / 2, window.getSize().y / 3);

}

void Game::dragSprite(sf::Sprite* sprite, sf::Vector2f& drag_offset)
{
	if (sprite != nullptr) {
		sf::Vector2f mouse_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
		//sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);

		sf::Vector2f drag_position = mouse_position - drag_offset;
		sprite->setPosition(drag_position.x, drag_position.y);
	}
}


