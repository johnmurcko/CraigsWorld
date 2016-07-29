#include "Origin.hpp"

Origin::Origin (float x, float y) {
	setX(x);
	setY(y);
}

void Origin::setX (float x) {
	this->x = x;
}

void Origin::setY (float y) {
	this->y = y;
}

float Origin::getX () {
	return x;
}

float Origin::getY () {
	return y;
}
