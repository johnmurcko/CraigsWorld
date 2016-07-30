#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Player : public Entity {
	private:
		float speed;
	public:
		Player (float x, float y, Origin * origin);
		float getSpeed ();
		void setSpeed (float speed);
		void draw (sf::RenderWindow * window);
};

