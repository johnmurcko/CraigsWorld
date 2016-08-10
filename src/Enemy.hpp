#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "CombatEntity.hpp"
#include "Target.hpp"
#include "Bullet.hpp"

class Enemy : public CombatEntity {
	private:
        static const int kTargetWidth = 70;
		static const int kTargetHeight = 108;
		static const int kTargetRange = 1000;
		static const int basic_enemy_one = 0;
		static const int basic_enemy_two = 1;
		float speed;
		bool is_wandering;
		int enemy_type;
		Target * target;
        sf::Clock * clock;
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
        void takeDamage();
		void draw(sf::RenderWindow * window);
		~Enemy();
};

#endif
