
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game(sf::RenderWindow& window);
	~Game();
	bool init();
	void update(float dt);
	void render();
	void mouseClicked(sf::Event event);
	void keyPressed(sf::Event event);
	void mouseButtonPressed(sf::Event event);
	void mouseButtonReleased(sf::Event event);
	bool in_menu = true;

	void newAnimal();
	bool passport_accepted;
	bool passport_rejected;
	bool should_accept;

	void dragSprite(sf::Sprite* sprite);

private:
	sf::RenderWindow& window;
	sf::Sprite ball;
	sf::Texture ball_texture;
	sf::Sprite background;
	sf::Texture background_texture;
	sf::Sprite* character;
	sf::Texture* animals = new sf::Texture[3];
	sf::Sprite* passport;
	sf::Texture* passports = new sf::Texture[3];
	sf::Text logo;
	sf::Text welcome;
	sf::Font myfont;
	sf::Text play;
	sf::Text quit;
	sf::Sprite* dragged = nullptr;

};

#endif // PLATFORMER_GAME_H
