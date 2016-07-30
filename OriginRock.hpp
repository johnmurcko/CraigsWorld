#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class OriginRock : public Entity {
	public:
        OriginRock(float x, float y, Origin * origin);
		void draw (sf::RenderWindow * window);
};
