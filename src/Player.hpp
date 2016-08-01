#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Player : public Entity {
	private:
		float speed;
		float acceleration;
		float max_speed;
		float angle;
		float last_thrust_angle;
		float x_velocity;
		float y_velocity;
	public:
		Player(float x, float y, Origin * origin);
		void setSpeed(float speed);
		void setAcceleration(float acceleration);
		void setMaxSpeed(float max_speed);
		void setAngle(float angle);
		void setLastThrustAngle(float last_thrust_angle);
		void setXVelocity(float x_velocity);
		void setYVelocity(float y_velocity);
		float getSpeed();
		float getAcceleration();
		float getMaxSpeed();
		float getAngle();
		float getLastThrustAngle();
		float getXVelocity();
		float getYVelocity();
		void forwardThrust(sf::Time * delta_time);
		void reverseThrust(sf::Time * delta_time);
		void enforceInertia(sf::Time * delta_time);
		void update(sf::Time * delta_time);
		void rotateLeft(sf::Time * delta_time);
		void rotateRight(sf::Time * delta_time);
		void draw(sf::RenderWindow * window);
};

