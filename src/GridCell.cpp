#include "GridCell.hpp"
#include "Entity.hpp"
#include "CombatEntity.hpp"
#include <algorithm>
#include <string>

GridCell::GridCell(float x, float y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
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
			&& !cell_left->hasEntity(cell_entity.at(i))) {
			
			cell_left->addEntity(cell_entity.at(i));
		}
		if (cell_entity.at(i)->getX()
			+ cell_entity.at(i)->getWidth() < getX()) {

			removeEntity(cell_entity.at(i));
			continue;
		}

		if (cell_entity.at(i)->getX() + cell_entity.at(i)->getWidth()
			> getX() + kWidth && !cell_right->hasEntity(cell_entity.at(i))) {

			cell_right->addEntity(cell_entity.at(i));
		}
		if (cell_entity.at(i)->getX() > getX() + kWidth) {
			removeEntity(cell_entity.at(i));
			continue;
		}

		if (cell_entity.at(i)->getY() < getY()
			&& cell_up->hasEntity(cell_entity.at(i))) {

			cell_up->addEntity(cell_entity.at(i));
		}
		if (cell_entity.at(i)->getY() + cell_entity.at(i)->getHeight()
			< getY()) {

			removeEntity(cell_entity.at(i));
			continue;
		}

		if (cell_entity.at(i)->getY() > getY() + kHeight
			&& !cell_down->hasEntity(cell_entity.at(i))) {
			
			cell_down->addEntity(cell_entity.at(i));
		}
		if (cell_entity.at(i)->getY() + cell_entity.at(i)->getHeight()
			> getY() + kHeight) {

			removeEntity(cell_entity.at(i));
			continue;
		}
	}
}

void GridCell::findCollisions() {

}

bool GridCell::hasEntity(Entity * entity) {
	for (unsigned int i = 0; i < cell_entity.size(); i++) {
		if (cell_entity.at(i) == entity) {
			return true;
		}
	}

	return false;
}

float GridCell::getX() {
	return x;
}

float GridCell::getY() {
	return y;
}
