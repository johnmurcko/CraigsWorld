#include "Star.hpp"

class FarStar : public Star {
    private:
    public:
        FarStar(float x, float y);
        void move(float x_delta, float y_delta);
        void draw(sf::RenderWindow * window);
        void update();
};
