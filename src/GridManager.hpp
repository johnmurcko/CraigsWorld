#include "GridCell.hpp"
#include <SFML/Graphics.hpp>

class GridManager {
	private:
		static const int kHorizontalCellCount = 50;
		static const int kVerticalCellCount = 50;
		static const int kCellWidth = 200;
		static const int kCellHeight = 200;
		GridCell * cell[kHorizontalCellCount][kVerticalCellCount];
		static GridManager * shared_grid_manager;
		static bool instance_exists;
	public:
		GridManager();	
		static GridManager * getInstance();
		void updateGrids();
		void draw(sf::RenderWindow * window);
};
