#ifndef TRAIL_H
#define TRAIL_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Trail : public Entity {
    private:
        static const int kTrailWidth = 20;
        static const int kTrailHeight = kTrailWidth;
        bool is_old;
        sf::Clock * clock;
    public:
        Trail(float x, float y, Origin * origin);
        void update();
        bool isOld();
        void draw(sf::RenderWindow * window);
        ~Trail();
};

#endif
