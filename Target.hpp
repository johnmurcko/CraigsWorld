#include "Entity.hpp"

class Target : public Entity {
	private:
		int width;
		int height;
	public:
		Target (float x, float y, int width, int height, Origin * origin);
		void setWidth (int width);
		void setHeight (int height);
		int getWidth ();
		int getHeight ();
		bool isIntersecting (Entity * entity);
}
