#include "GridManager.hpp"

GridManager::GridManager() {
	for (int i = 0; i < kHorizontalCellCount; i++) {
		for (int j = 0; j < kVerticalCellCount; j++) {
			cell[i][j] = new GridCell(i * kCellWidth, j * kCellHeight,
				kCellWidth, kCellHeight);
			if (i - 1 >= 0) {
				cell[i][j]->setCellRight(cell[i - 1][j]);
			}
			if (i + 1 < kHorizontalCellCount) {
				cell[i][j]->setCellLeft(cell[i + 1][j]);
			}
			if (j - 1 >= 0) {
				cell[i][j]->setCellUp(cell[i][j - 1]);
			}
			if (j + 1 < kVerticalCellCount) {
				cell[i][j]->setCellDown(cell[i][j + 1]);
			}
		}
	}
}

GridManager * GridManager::getInstance() {
    if (instance_exists) {
        return shared_grid_manager;
    }

    instance_exists = true;
    shared_grid_manager = new GridManager();

    return shared_grid_manager;
}

void GridManager::updateGrids() {
	for (int i = 0; i < kHorizontalCellCount; i++) {
		for (int j = 0; j < kVerticalCellCount; j++) {
			cell[i][j]->update();
		}
	}
}

void GridManager::draw(sf::RenderWindow * window) {
	for (int i = 0; i < kHorizontalCellCount; i++) {
		for (int j = 0; j < kVerticalCellCount; j++) {
			cell[i][j]->draw(window);
		}
	}
}
