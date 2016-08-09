#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "CombatEntity.hpp"
#include "Trail.hpp"
#include "PlayerBullet.hpp"
#include "Enemy.hpp"

class Player : public CombatEntity {
	private:
        static const float kDefaultAcceleration = 50;
        static const float kDefaultMaxSpeed = 5;
        static const float kQuarterRotation = 90;
        static const float kFlipRotation = 180;
        static const int kWidth = 142;
        static const int kHeight = 284;
		float speed;
		float acceleration;
		float max_speed;
		float angle;
		float last_thrust_angle;
        std::vector<Trail*> trail;
        std::vector<PlayerBullet*> bullet;
        sf::Clock * clock;
        static bool instance_exists;
        static Player * shared_player;
	public:
		Player(float x, float y);
		static Player * getInstance();
		void setSpeed(float speed);
		void setAcceleration(float acceleration);
		void setMaxSpeed(float max_speed);
		void setAngle(float angle);
		void setLastThrustAngle(float last_thrust_angle);
		float getSpeed();
		float getAcceleration();
		float getMaxSpeed();
		float getAngle();
		float getLastThrustAngle();
		void forwardThrust(sf::Time * delta_time);
		void reverseThrust(sf::Time * delta_time);
		void enforceInertia(sf::Time * delta_time);
		void update(std::vector<CombatEntity*> * enemy, sf::Time * delta_time);
		void rotateLeft(sf::Time * delta_time);
		void rotateRight(sf::Time * delta_time);
        void createTrail();
        void fireBullet();
		void loseHealth();
		void draw(sf::RenderWindow * window);
		~Player();
};
