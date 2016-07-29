#ifndef ORIGIN_H
#define ORIGIN_H
class Origin {
	private:
		float x;
		float y;
	public:
		Origin (float x, float y);
		void setX (float x);
		void setY (float y);
		float getX ();
		float getY ();
};
#endif
