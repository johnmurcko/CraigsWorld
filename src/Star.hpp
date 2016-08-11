#ifndef STAR_H
#define STAR_H

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Star : public Entity {
	public:
        Star(float x, float y);
        void update();
		void draw(sf::RenderWindow * window);
};

#endif
