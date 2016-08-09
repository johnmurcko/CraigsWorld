#ifndef TRAIL_H
#define TRAIL_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Trail : public Entity {
    private:
        static const int kTrailRadius = 40;
        float radius;
        float transparency;
        bool is_old;
        sf::Clock * clock;
    public:
        Trail(float x, float y);
        void update(sf::Time * delta_time);
        void setRadius(float radius);
        void setTransparency(float transparency);
        float getRadius();
        float getTransparency();
        bool isOld();
        void draw(sf::RenderWindow * window);
        ~Trail();
};

#endif
