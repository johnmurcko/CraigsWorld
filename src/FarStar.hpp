#include "Star.hpp"

class FarStar : public Star {
    private:
    public:
        FarStar(float x, float y);
        void draw(sf::RenderWindow * window);
        void update();
};
