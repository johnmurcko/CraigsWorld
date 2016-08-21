#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Origin.hpp"
#include "GridCell.hpp"
#include <string>

class Entity {
	protected:
		float x;
		float y;
		int width;
		int height;
		float last_origin_x;
		float last_origin_y;
		float x_velocity;
		float y_velocity;
		float angle;
		Origin * origin;
		std::vector<GridCell*> cell;
		std::string type;
	public:
		void setX(float x);
		void setY(float y);
		void setWidth(int width);
		void setHeight(int height);
		void setVelocity(float x_velocity, float y_velocity);
		void setXVelocity(float x_velocity);
		void setYVelocity(float y_velocity);
		void setAngle(float angle);
		void setType(std::string type);
		float getX();
		float getY();
		float getCenterX();
		float getCenterY();
		int getWidth();
		int getHeight();
		float getXVelocity();
		float getYVelocity();
		float getAngle();
		std::string getType();
		virtual void move(float x_delta, float y_delta);
		bool isIntersecting(Entity * entity);
		float distanceFrom(Entity * entity);
		float angleTo(Entity * entity);
		void addCell(GridCell * new_cell);
		bool isInView();
		void update();
		virtual void update(sf::Time * delta_time) {};
		virtual void draw(sf::RenderWindow * window) {};
		virtual ~Entity() {};
};

#endif
