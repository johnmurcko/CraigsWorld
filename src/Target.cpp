#include "Target.hpp"

Target::Target(float x, float y, int width, int height, Origin * origin) {
	this->origin = origin;
    last_origin_x = origin->getX();
	last_origin_y = origin->getY();
	setX(x);
	setY(y);
	setWidth(width);
	setHeight(height);
}

