#ifndef TRAIL_H
#define TRAIL_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Trail : public Entity {
    private:
        static const int kTrailWidth = 20;
        static const int kTrailHeight = kTrailWidth;
    public:
        Trail(float x, float y, Origin * origin);
        void draw(sf::RenderWindow * window);
};

#endif
