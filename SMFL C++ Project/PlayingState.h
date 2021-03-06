#pragma once
#include "State.h"
#include "Bullet.h"
#include <array>


class Asteroids;
class Player;

class PlayingState :
	public State
{
public :
	PlayingState(sf::Text& text, StateMachine& machine, sf::RenderWindow& window, bool replace = true);
	PlayingState(const PlayingState&) = delete;
	PlayingState& operator =(const PlayingState&) = delete;
	~PlayingState();

	void UpdateKeyboardInputs(sf::Keyboard::Key key, bool isPressed);

	void UpdateEvents() override;
	void Update() override;
	void Render() override;

private:
	//Variables and Booleans


	//Arrays


	//Vectors


	//Class objects
	std::unique_ptr<Player> player = nullptr;
	std::unique_ptr<Bullet> pBullet = nullptr;
	std::unique_ptr<Asteroids> pAsteroid = nullptr;
	bool isGamePaused = true;
	//	FPSCounter fpsCounter;
	//	Text versionText;
	bool playerShooting;

	std::vector<std::unique_ptr<Asteroids>> asteroidVector;
	std::vector<std::unique_ptr<Bullet>> bulletVector;

	//SFML
	sf::Event sfEvent;
	sf::Texture playerTexture;
	sf::Texture bulletTexture;
	sf::Clock dtClock;
	sf::Time time;
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	std::array<sf::Texture, 4> asteroidTextures;
	int score;
	sf::Text scoretext;
	sf::Font font;
	sf::Text lifeText;
	sf::Text playerName;
	std::string playerInput;
	bool NameDefined = false;
	bool isGameOver = false;
	int cpt = 0;
};
