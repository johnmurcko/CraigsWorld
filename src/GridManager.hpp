#include "GridCell.hpp"
#include "Entity.hpp"
#include <SFML/Graphics.hpp>

class GridManager {
	private:
		static const int kHorizontalCellCount = 10;
		static const int kVerticalCellCount = 10;
		static const int kCellWidth = 200;
		static const int kCellHeight = 200;
		static const int kXOffset = 0;
		static const int kYOffset = 0;
		GridCell * cell[kHorizontalCellCount][kVerticalCellCount];
		static GridManager * shared_grid_manager;
		static bool instance_exists;
	public:
		GridManager();	
		static GridManager * getInstance();
		void updateGrids();
		void draw(sf::RenderWindow * window);
		void assignEntityToCells(Entity * entity);
};
