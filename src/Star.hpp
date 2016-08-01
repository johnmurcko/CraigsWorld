#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Star : public Entity {
	public:
        Star(float x, float y, Origin * origin);
        void update();
		void draw(sf::RenderWindow * window);
};
