#ifndef COMBAT_ENTITY_H
#define COMBAT_ENTITY_H
#include "Entity.hpp"

class CombatEntity : public Entity {
	private:
		int damage;
		bool destroyed;
	public:
		virtual void takeDamage() {};
		void setDestroyed(bool destroyed);
		bool isDestroyed();
};

#endif // COMBAT_ENTITY_H
