#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "Player.hpp"
#include "Star.hpp"
#include "Enemy.hpp"

const int kStarCount = 100;
const int kInitialEnemyCount = 50;

int enemy_count;

void gameInit();
void gameUpdate(sf::RenderWindow * window, sf::Time * delta_time);
void draw(sf::RenderWindow * window);
void eventKeyboardListener(sf::Event * event);
void realTimeKeyboardListener(sf::RenderWindow * window, sf::Time * delta_time);
void createStars();
void createEnemies();
void dealloc();

Entity ** entity;
Player * player;
Origin * origin;
Star ** star;
std::vector<CombatEntity*> enemy;

int main()
{
	sf::RenderWindow window(sf::VideoMode(kWindowWidth, kWindowHeight), "Craig's World");

	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	srand(time(NULL));

    gameInit();

    sf::Clock delta_clock;
	sf::Time delta_time;

    //game loop
	while (window.isOpen()) {
	    float last_time = 0;
		delta_time = delta_clock.restart();

        gameUpdate(&window, &delta_time);
        draw(&window);
		sf::Event event;

		while (window.pollEvent(event)) {
            eventKeyboardListener(&event);

			if (event.type == sf::Event::Closed)
				window.close();
		}

		float fps = 1.f / (delta_time.asSeconds() - last_time);
		std::cout << fps << '\n';
	}

	dealloc();

    return 0;
}

void gameInit() {
	origin = Origin::getInstance();
	player = Player::getInstance();
	createStars();
	createEnemies();
}

void createStars() {
    star = new Star*[kStarCount];
	for (int i = 0; i < kStarCount; i++) {
		int rand_x = rand() % kWindowWidth;
		int rand_y = rand() % kWindowHeight;
		star[i] = new Star(rand_x, rand_y);
	}
}

void createEnemies() {
	for (int i = 0; i < kInitialEnemyCount; i++) {
		int rand_x = rand() % kMapWidth - kWindowWidth;
		int rand_y = rand() % kMapHeight - kWindowHeight;
		enemy.push_back(new Enemy(rand_x, rand_y));
	}
}

void gameUpdate(sf::RenderWindow * window, sf::Time * delta_time) {
    realTimeKeyboardListener(window, delta_time);

    player->update(&enemy, delta_time);

	for (int i = 0; i < kStarCount; i++) {
		star[i]->update();
	}

	for (unsigned int i = 0; i < enemy.size(); i++) {
		enemy.at(i)->update(delta_time);
	}
}

void draw(sf::RenderWindow * window) {
	window->clear(sf::Color::Black);

	for (int i = 0; i < kStarCount; i++) {
		star[i]->draw(window);
	}

    for (unsigned int i = 0; i < enemy.size(); i++) {
        enemy.at(i)->draw(window);
    }

	player->draw(window);

	window->display();
}

void realTimeKeyboardListener(sf::RenderWindow * window, sf::Time * delta_time) {
        // movement keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player->rotateLeft(delta_time);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player->rotateRight(delta_time);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player->forwardThrust(delta_time);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player->reverseThrust(delta_time);
        }
        else {
            player->enforceInertia(delta_time);
        }

}

void eventKeyboardListener(sf::Event * event) {
    if (event->type == sf::Event::KeyReleased) {
        if (event->key.code == sf::Keyboard::LControl) {
            player->fireBullet();
        }
    }
}

void dealloc() {
    delete player;
    delete origin;
    for (int i = 0; i < kStarCount; i++) {
        delete star[i];
    }
}
