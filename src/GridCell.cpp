#include "GridCell.hpp"
#include <algorithm>

GridCell::GridCell(int x, int y, GridCell * cell_right,
	GridCell * cell_left, GridCell * cell_up, GridCell * cell_down) {

	this->x = x;
	this->y = y;
	this->cell_right = cell_right;
	this->cell_left = cell_left;
	this->cell_up = cell_up;
	this->cell_down = cell_down;
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

void GridCell::update() {

}

void GridCell::findCollisions() {

}
