#include "PlayerBullet.hpp"
#include "Bullet.hpp"

PlayerBullet::PlayerBullet(float x, float y, float angle) : Bullet(x, y, angle) {

}

void PlayerBullet::update(std::vector<CombatEntity*> * bullet_target, sf::Time * delta_time) {
    if (!isDestroyed()) {
        for (unsigned int i = 0; i < bullet_target->size(); i++) {
            if (isIntersecting(bullet_target->at(i))) {
                bullet_target->at(i)->takeDamage();
               // destroyed = true;
                break;
            }
        }

        move(getXVelocity() * delta_time->asSeconds(),
            getYVelocity() * delta_time->asSeconds());
    }
}
