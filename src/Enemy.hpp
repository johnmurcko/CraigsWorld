#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "CombatEntity.hpp"
#include "Target.hpp"
#include "Bullet.hpp"

class Enemy : public CombatEntity {
	protected:
        static const int kTargetWidth = 50;
		static const int kTargetHeight = 50;
		static const int kTargetRange = 1000;
		static const int basic_enemy_one = 0;
		static const int basic_enemy_two = 1;
		float speed;
		bool is_wandering;
		int enemy_type;
		Target * target;
        sf::Clock * clock;
		std::vector<Bullet*> bullet;
		sf::SoundBuffer fire_buffer;
        sf::Sound fire_sound;
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
		virtual void draw(sf::RenderWindow * window) {};
		~Enemy();
};

#endif
