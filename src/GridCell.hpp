#include "Entity.hpp"
#include <stdlib.h>
#include <SFML/Graphics.hpp>

class GridCell {
	private:
		float x;
		float y;
		int width;
		int height;
		GridCell * cell_right;
		GridCell * cell_left;
		GridCell * cell_up;
		GridCell * cell_down;
		std::vector<Entity*> cell_entity;
	public:
		GridCell(float x, float y, int width, int height);
		void setCellRight(GridCell * cell_right);
		void setCellLeft(GridCell * cell_left);
		void setCellUp(GridCell * cell_up);
		void setCellDown(GridCell * cell_down);
		void addEntity(Entity * entity);
		void removeEntity(Entity * entity);
		void removeEntity(int index);
		void update();
		void findCollisions();
		bool hasEntity(Entity * entity);
		float getX();
		float getY();
		void draw(sf::RenderWindow * window);
};
