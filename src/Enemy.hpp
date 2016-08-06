#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "CombatEntity.hpp"
#include "Target.hpp"
#include "Bullet.hpp"

class Enemy : public CombatEntity {
	private:
        static const int kTargetWidth = 50;
		static const int kTargetHeight = kTargetWidth;
		static const int kTargetRange = 100;
		float speed;
		bool is_wandering;
		Target * target;
		std::vector<Bullet*> bullet;
	public:
		Enemy(float x, float y);
		void setSpeed(float speed);
		float getSpeed();
		void update(sf::Time * delta_time);
		void generateWanderTarget();
		void wander(sf::Time * delta_time);
		void followPlayer(sf::Time * delta_time);
        void fireBullet();
		void draw(sf::RenderWindow * window);
		~Enemy();
};

#endif
