#ifndef COMBAT_ENTITY_H
#define COMBAT_ENTITY_H
#include "Entity.hpp"

class CombatEntity : public Entity {
	private:
		int damage;
	public:
		virtual void takeDamage() {};
};

#endif // COMBAT_ENTITY_H
