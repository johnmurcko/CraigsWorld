#include "EnemyUFO.hpp"

EnemyUFO::EnemyUFO(float x, float y) : Enemy(x, y) {
	setWidth(kWidth);
	setHeight(kHeight);
}

void EnemyUFO::draw(sf::RenderWindow * window) {
    for (unsigned int i = 0; i < bullet.size(); i++) {
        bullet.at(i)->draw(window);
	}

	sf::RectangleShape enemy_rect(sf::Vector2f(getWidth(),getHeight()));
	enemy_rect.setPosition(getX(), getY());
	enemy_rect.setFillColor(sf::Color::Red);
	sf::RectangleShape target_rect(sf::Vector2f(50, 50));
	target_rect.setPosition(target->getX(), target->getY());
	target_rect.setFillColor(sf::Color::Green);
	//window->draw(enemy_rect);

	sf::Sprite enemy_sprite;
	sf::Texture enemy_texture;
    enemy_texture.loadFromFile("res/enemy-2.png");
	enemy_sprite.setTexture(enemy_texture, true);
	enemy_sprite.setPosition(getX(), getY());


	window->draw(enemy_sprite);
	//window->draw(target_rect);
}
