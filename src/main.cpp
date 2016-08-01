#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "Player.hpp"
#include "Star.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

const int kStarCount = 1000;
const int kInitialEnemyCount = 1000;

int enemy_count;

void gameInit();
void gameUpdate(sf::RenderWindow * window, sf::Time * delta_time);
void draw(sf::RenderWindow * window);
void keyboardListener(sf::RenderWindow * window, sf::Time * delta_time);
void createStars();
void createEnemies();
void dealloc();

Entity ** entity;
Player * player;
Origin * origin;
Star ** star;
Enemy ** enemy;
std::vector<Bullet*> bullet;

int main()
{
	sf::RenderWindow window(sf::VideoMode(kWindowWidth, kWindowHeight), "Craig's World");

	srand(time(NULL));

    gameInit();

    sf::Clock delta_clock;
	sf::Time delta_time;


    //game loop
	while (window.isOpen()) {
        gameUpdate(&window, &delta_time);
        draw(&window);
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		delta_time = delta_clock.restart();
	}

	dealloc();

    return 0;
}

void gameInit() {
	origin = new Origin(0, 0);
	player = new Player(kWindowWidth / 2, kWindowHeight / 2, origin);
	createStars();
	createEnemies();
}

void createStars() {
    star = new Star*[kStarCount];
	for (int i = 0; i < kStarCount; i++) {
		int rand_x = rand() % kWindowWidth;
		int rand_y = rand() % kWindowHeight;
		star[i] = new Star(rand_x, rand_y, origin);
	}
}

void createEnemies() {
    enemy_count = kInitialEnemyCount;
    enemy = new Enemy*[kInitialEnemyCount];
	for (int i = 0; i < kInitialEnemyCount; i++) {
		int rand_x = rand() % kMapWidth - kWindowWidth;
		int rand_y = rand() % kMapHeight - kWindowHeight;
		enemy[i] = new Enemy(rand_x, rand_y, origin);
	}
}

void gameUpdate(sf::RenderWindow * window, sf::Time * delta_time) {
    keyboardListener(window, delta_time);

	for (int i = 0; i < kStarCount; i++) {
		star[i]->update();
	}

	for (unsigned int i = 0; i < bullet.size(); i++) {
        bullet.at(i)->update(delta_time);
	}

	for (int i = 0; i < kInitialEnemyCount; i++) {
		enemy[i]->update(delta_time);
	}

}

void draw(sf::RenderWindow * window) {
	window->clear(sf::Color::Black);

	for (int i = 0; i < kStarCount; i++) {
		star[i]->draw(window);
	}

    for (unsigned int i = 0; i < bullet.size(); i++) {
        bullet.at(i)->draw(window);
	}

    for (int i = 0; i < enemy_count; i++) {
        enemy[i]->draw(window);
    }

	player->draw(window);

	window->display();
}

void keyboardListener(sf::RenderWindow * window, sf::Time * delta_time) {

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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        Bullet * new_bullet = new Bullet(player->getX(), player->getY(), player->getAngle(), origin);
        bullet.push_back(new_bullet);
	}
}

void dealloc() {
    delete player;
    delete origin;
    for (int i = 0; i < kStarCount; i++) {
        delete star[i];
    }
}
