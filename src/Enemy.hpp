#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Entity.hpp"
#include "Target.hpp"

class Enemy : public Entity {
	private:
        static const int kTargetWidth = 50;
		static const int kTargetHeight = kTargetWidth;
		static const int kTargetRange = 100;
		float speed;
		Target * target;
	public:
		Enemy(float x, float y, Origin * origin);
		void setSpeed(float speed);
		float getSpeed();
		void update(sf::Time * delta_time);
		void generateWanderTarget();
		void draw(sf::RenderWindow * window);
		~Enemy();
};
