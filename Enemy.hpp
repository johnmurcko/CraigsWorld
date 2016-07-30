#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Enemy : public Entity {
	private:
		float speed;
	public:
		Enemy (float x, float y, Origin * origin);
		void setSpeed (float speed);
		float getSpeed ();
		void generateWanderTarget ();
		void draw (sf::RenderWindow * window);
};
