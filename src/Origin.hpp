#ifndef ORIGIN_H
#define ORIGIN_H

class Origin {
	private:
		float x;
		float y;
		float speed;
		static bool instance_exists;
		static Origin * shared_origin;
	public:
		Origin(float x, float y);
		static Origin * getInstance();
		void setX(float x);
		void setY(float y);
		float getX();
		float getY();
		void move(float x_delta, float y_delta);
		float getSpeed();
};

#endif
