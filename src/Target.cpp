#include "Target.hpp"

Target::Target (float x, float y, int width, int height, Origin * origin) {
	setX (x);
	setY (y);
	setWidth (width);
	setHeight (height);
	this->origin = origin;
}

bool isIntersecting (Entity * entity) {
	if (entity->getX () >= getX ()
		|| entity->getX () + entity->getWidth() <= getX () + getWidth ()
		|| entity->getY () >= getY ()
		|| entity->getY () <= getY () + getHeight ()) {

		return true;
	}

	return false;
}
