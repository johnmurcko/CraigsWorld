#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Rock : public Entity {
	public:
        Rock ();
        Rock(float x, float y, Origin * origin);
		void draw (sf::RenderWindow * window);
};
