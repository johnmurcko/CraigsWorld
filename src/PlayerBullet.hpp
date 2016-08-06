#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H

#include "Bullet.hpp"

class PlayerBullet : public Bullet {
    public:
        PlayerBullet(float x, float y, float angle);
		void update(std::vector<CombatEntity*> * bullet_target, sf::Time * delta_time);
};
#endif
