#include "Target.hpp"

Target::Target(float x, float y, int width, int height, Origin * origin) {
	this->origin = origin;
	setX(x);
	setY(y);
	setWidth(width);
	setHeight(height);
}

