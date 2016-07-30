#ifndef ORIGIN_H
#define ORIGIN_H

class Origin {
	private:
		float x;
		float y;
		float speed;
	public:
		Origin (float x, float y);
		void setX (float x);
		void setY (float y);
		float getX ();
		float getY ();
		void move (float x_delta, float y_delta);
		float getSpeed();
};

#endif
