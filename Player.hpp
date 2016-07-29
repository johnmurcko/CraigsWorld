#include <SFML/Graphics.hpp>
#include "Origin.hpp"

class Player {
	private:
		float x, y;
		Origin * origin;
	public:
		Player(float x, float y, Origin * origin);
		float getX();
		float getY();
		void setX(float x);
		void setY(float y);
		void draw(sf::RenderWindow * window);
};

