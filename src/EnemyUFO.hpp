#include "Enemy.hpp"

class EnemyUFO : public Enemy {
	private:
		static const float kWidth = 148;
		static const float kHeight = 154;
	public:
		EnemyUFO(float x, float y);
		void draw(sf::RenderWindow * window);
};
