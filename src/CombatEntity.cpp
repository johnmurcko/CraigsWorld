#include "CombatEntity.hpp"

void CombatEntity::setDestroyed(bool destroyed) {
    this->destroyed = destroyed;
}

bool CombatEntity::isDestroyed() {
    return destroyed;
}
