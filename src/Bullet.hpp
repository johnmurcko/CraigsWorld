#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Entity.hpp"
#include "Constants.hpp"

class Bullet : Entity {
    private:
        static const float kDestroyDistance = 500;
        static const float kBulletSpeed = 1000;
        float speed;
        float angle;
        float x_velocity;
        float y_velocity;
    public:
        Bullet(float x, float y, float angle, Origin * origin);
		void setSpeed(float speed);
		void setAngle(float angle);
		void setXVelocity(float x_velocity);
		void setYVelocity(float y_velocity);
		float getSpeed();
		float getAngle();
		float getXVelocity();
		float getYVelocity();
		void update(sf::Time * delta_time);
		void draw(sf::RenderWindow * window);
};
