#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "OriginRock.hpp"
#include "Rock.hpp"

const int kWindowWidth = 500;
const int kWindowHeight = 500;
const int kMapWidth = 1500;
const int kMapHeight = 1500;
const int kRockCount = 1000;

const float kPlayerBorderLimit = 10;

void gameInit();
void gameUpdate(sf::Time delta_time);
void draw(sf::RenderWindow * window);
void keyboardListener(sf::Time delta_time);
void createRocks();
void dealloc();

Player * player;
Origin * origin;
OriginRock * origin_rock;
Rock ** rock;

int main()
{
	sf::RenderWindow window(sf::VideoMode(kWindowWidth, kWindowHeight), "meme time ;)");

    gameInit();

    sf::Clock delta_clock;
	sf::Time delta_time;

    //game loop
	while (window.isOpen ()) {
        gameUpdate (delta_time);
        draw (&window);
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		delta_time = delta_clock.restart ();
	}

	dealloc();

    return 0;
}

void gameInit () {
	origin = new Origin (0, 0);
	player = new Player (100, 100, origin);
	origin_rock = new OriginRock (100, 100, origin);
	createRocks ();
}

void createRocks () {
    rock = new Rock*[kRockCount];
	srand (time (NULL));
	for (int i = 0; i < kRockCount; i++) {
		int rand_x = rand () % kMapWidth - kWindowWidth;
		int rand_y = rand () % kMapHeight - kWindowHeight;
		rock[i] = new Rock (rand_x, rand_y, origin);
	}
}

void gameUpdate (sf::Time delta_time) {
    keyboardListener (delta_time);
    origin_rock->update ();
	for (int i = 0; i < kRockCount; i++) {
		rock[i]->update ();
	}
}

void draw (sf::RenderWindow * window) {
	window->clear(sf::Color::Black);

	for (int i = 0; i < kRockCount; i++) {
		rock[i]->draw(window);
	}

	origin_rock->draw(window);
	player->draw(window);
	window->display();
}

void keyboardListener (sf::Time delta_time) {

	// movement keys
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left)) {
		if (player->getX () >= 0 + kPlayerBorderLimit) {
			player->move (-1 * player->getSpeed() * delta_time.asSeconds (), 0);
		}
		else {
			origin->move (1 * player->getSpeed() * delta_time.asSeconds (), 0);
		}
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right)) {
		if (player->getX () <= kWindowWidth - kPlayerBorderLimit) {
			player->move (1 * player->getSpeed() * delta_time.asSeconds (), 0);
		}
		else {
			origin->move (-1 * player->getSpeed() * delta_time.asSeconds (), 0);
		}
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up)) {
		if (player->getY () >= 0 + kPlayerBorderLimit) {
			player->move (0, -1 * player->getSpeed() * delta_time.asSeconds ());
		}
		else {
			origin->move (0, 1 * player->getSpeed() * delta_time.asSeconds ());
		}
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down)) {
		if (player->getY () <= kWindowHeight - kPlayerBorderLimit) {
			player->move (0, 1 * player->getSpeed() * delta_time.asSeconds ());
		}
		else {
			origin->move (0, -1 * player->getSpeed() * delta_time.asSeconds ());
		}
	}
}

void dealloc () {
    delete player;
    delete origin_rock;
    delete origin;
    for (int i = 0; i < kRockCount; i++) {
        delete rock[i];
    }
}
