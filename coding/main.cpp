#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML TUTORIAL");
    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Blue);
    sf::CircleShape shape1(100.f);
    shape1.setFillColor(sf::Color::Red);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(shape1);
        window.display();
    }

    return 0;
}