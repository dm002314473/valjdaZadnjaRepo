#include <SFML\Graphics.hpp>

class Tower
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2i location;
    int damage;

public:
    Tower(sf::Vector2i location, int damage);
    Tower *createTower();
};