#include "CombatEntity.hpp"

class Astroid : public CombatEntity {
	private:
		static int const kWidth = 50;
		static int const kHeight = 50;
	public:
		Astroid(float x, float y);
		void update(sf::Time * delta_time);
		void draw(sf::RenderWindow * window);
};
