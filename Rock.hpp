#include <SFML/Graphics.hpp>
#include "Origin.hpp"

class Rock {
	private:
		float x;
		float y;
		float last_origin_x;
		float last_origin_y;
		Origin * origin;
	public:
        Rock ();
        Rock(float x, float y, Origin * origin);
		void setX (float x);
		void setY (float y);
		float getX ();
		float getY ();
		void update ();
		void draw (sf::RenderWindow * window);
};
