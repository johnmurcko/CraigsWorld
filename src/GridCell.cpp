#include "GridCell.hpp"
#include "Entity.hpp"
#include "CombatEntity.hpp"
#include <algorithm>
#include <string>
#include <sstream>

GridCell::GridCell(float x, float y, int width, int height) {
	setX(x);
	setY(y);
	setWidth(width);
	setHeight(height);
}

void GridCell::setCellRight(GridCell * cell_right) {
	this->cell_right = cell_right;
}

void GridCell::setCellLeft(GridCell * cell_left) {
	this->cell_left = cell_left;
}

void GridCell::setCellUp(GridCell * cell_up) {
	this->cell_up = cell_up;
}

void GridCell::setCellDown(GridCell * cell_down) {
	this->cell_down = cell_down;
}

void GridCell::addEntity(Entity * entity) {
	cell_entity.push_back(entity);
}

void GridCell::removeEntity(Entity * entity) {
	cell_entity.erase(std::remove(cell_entity.begin(), cell_entity.end(),
				entity), cell_entity.end());
}

void GridCell::removeEntity(int index) {
	cell_entity.erase(cell_entity.begin() + index);
}

void GridCell::update() {
	for (unsigned int i = 0; i < cell_entity.size(); i++) {
		if (cell_entity.at(i)->getType().compare("combat_entity")) {
			if (((CombatEntity*) cell_entity.at(i))->isDestroyed()) {
				cell_entity.erase(cell_entity.begin() + i);
				i--;
				continue;
			}
		}

		if (cell_entity.at(i)->getX() < getX()
			&& cell_left && !cell_left->hasEntity(cell_entity.at(i))) {

			cell_left->addEntity(cell_entity.at(i));
		}
		if (cell_entity.at(i)->getX()
			+ cell_entity.at(i)->getWidth() < getX()) {

			removeEntity(cell_entity.at(i));
			i--;
			continue;
		}

		if (cell_entity.at(i)->getX() + cell_entity.at(i)->getWidth()
			> getX() + getWidth() && cell_right
			&& !cell_right->hasEntity(cell_entity.at(i))) {

			cell_right->addEntity(cell_entity.at(i));
		}
		if (cell_entity.at(i)->getX() > getX() + getWidth()) {
			removeEntity(cell_entity.at(i));
			i--;
			continue;
		}

		if (cell_entity.at(i)->getY() < getY()
			&& cell_up && cell_up->hasEntity(cell_entity.at(i))) {

			cell_up->addEntity(cell_entity.at(i));
		}
		if (cell_entity.at(i)->getY() + cell_entity.at(i)->getHeight()
			< getY()) {

			removeEntity(cell_entity.at(i));
			i--;
			continue;
		}

		if (cell_entity.at(i)->getY() + cell_entity.at(i)->getHeight()
			> getY() + getHeight()
			&& cell_down && !cell_down->hasEntity(cell_entity.at(i))) {

			cell_down->addEntity(cell_entity.at(i));
		}
		if (cell_entity.at(i)->getY() > getY() + getHeight()) {

			removeEntity(cell_entity.at(i));
			i--;
			continue;
		}
	}
}

void GridCell::findCollisions() {

}

bool GridCell::containsEntity(Entity * entity) {
	if (entity->getX() + entity->getWidth() >= getX()
		&& entity->getX() <= getX() + getWidth()
		&& entity->getY() + entity->getHeight() >= getY()
		&& entity->getY() <= getY() + getHeight()) {

        return true;
    }
    return false;
}

bool GridCell::hasEntity(Entity * entity) {
	for (unsigned int i = 0; i < cell_entity.size(); i++) {
		if (cell_entity.at(i) == entity) {
			return true;
		}
	}

	return false;
}

void GridCell::setX(float x) {
    this->x = x;
}

void GridCell::setY(float y) {
    this->y = y;
}

void GridCell::setWidth(float width) {
	this->width = width;
}

void GridCell::setHeight(float height) {
	this->height = height;
}

float GridCell::getX() {
	return x;
}

float GridCell::getY() {
	return y;
}

float GridCell::getWidth() {
	return width;
}

float GridCell::getHeight() {
	return height;
}

void GridCell::draw(sf::RenderWindow * window) {
	sf::RectangleShape cell_rect(sf::Vector2f(getWidth(), getHeight()));
	cell_rect.setPosition(sf::Vector2f(getX(), getY()));
	cell_rect.setOutlineColor(sf::Color::White);
	cell_rect.setFillColor(sf::Color::Transparent);
	cell_rect.setOutlineThickness(1.0f);

	sf::Text entity_count;

	std::stringstream ss;
	ss << cell_entity.size();

	sf::Font font;
	font.loadFromFile("res/FreeSans.ttf");
	entity_count.setFont(font);
	entity_count.setString(ss.str());
	entity_count.setCharacterSize(12);
	entity_count.setPosition(sf::Vector2f(getX(), getY()));
	entity_count.setColor(sf::Color::White);

    window->draw(cell_rect);
	window->draw(entity_count);
}
