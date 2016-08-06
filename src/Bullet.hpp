#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Entity.hpp"
#include "CombatEntity.hpp"
#include "Constants.hpp"

class Bullet : public Entity {
    private:
        static const float kDestroyDistance = 500;
        static const float kBulletSpeed = 1000;
        float speed;
        float angle;
        float x_velocity;
        float y_velocity;
        bool destroyed;
    public:
        Bullet(float x, float y, float angle);
		void setSpeed(float speed);
		void setAngle(float angle);
		void setVelocity(float x_velocity, float y_velocity);
		void setXVelocity(float x_velocity);
		void setYVelocity(float y_velocity);
		float getSpeed();
		float getAngle();
		float getXVelocity();
		float getYVelocity();
		bool isDestroyed();
		void update(std::vector<CombatEntity*> * bullet_target, sf::Time * delta_time);
		void draw(sf::RenderWindow * window);
};

#endif // BULLET_H
