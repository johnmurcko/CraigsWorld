#include "Target.hpp"

Target::Target (float x, float y, int width, int height, Origin * origin) {
	setX (x);
	setY (y);
	setWidth (width);
	setHeight (height);
	this->origin = origin;
}

void Target::setX (float x) {
	this->x = x;
}

void Target::setY (float y) {
	this->y = y;
}

void Target::setWidth (int width) {
	this->width = width;
}

void Target::setHeight (int height) {
	this->height = height;
}

float Target::getX () {
	return x;
}

float Target::getY () {
	return y;
}

int Target::getWidth () {
	return width;
}

int Target::getHeight () {
	return height;
}

