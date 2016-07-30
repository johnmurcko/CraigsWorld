#ifndef ENTITY_H
#define ENTITY_H

#include "Origin.hpp"

class Entity {
	protected:
		float x;
		float y;
		float last_origin_x;
		float last_origin_y;
		Origin * origin;
	public:
		void setX (float x);
		void setY (float y);
		float getX ();
		float getY ();
		void move (float x_delta, float y_delta);
		void update ();
};

#endif
