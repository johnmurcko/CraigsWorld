#include "Enemy.hpp"

class EnemySquid : public Enemy {
	private:
		static const float kWidth = 70;
		static const float kHeight = 108;
	public:
		EnemySquid(float x, float y);
		void draw(sf::RenderWindow * window);
};
