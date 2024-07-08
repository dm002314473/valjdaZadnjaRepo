#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib> // for rand()

// Function to calculate the distance between two points
float distance(sf::Vector2f point1, sf::Vector2f point2)
{
    return std::sqrt((point2.x - point1.x) * (point2.x - point1.x) +
                     (point2.y - point1.y) * (point2.y - point1.y));
}

// Enemy class
class Enemy
{
public:
    Enemy(sf::Texture &texture, const std::vector<sf::Vector2f> &path, sf::Vector2f scale)
        : sprite(texture), path(path), currentWaypoint(0), speed(100.0f)
    {
        if (!path.empty())
        {
            sprite.setPosition(path[0]);
        }
        sprite.setScale(scale); // Set the scale for the enemy sprite
    }

    void update(float deltaTime)
    {
        if (currentWaypoint < path.size())
        {
            sf::Vector2f position = sprite.getPosition();
            sf::Vector2f target = path[currentWaypoint];
            sf::Vector2f direction = target - position;
            float distanceToNext = distance(position, target);

            // Normalize direction vector and move towards target
            if (distanceToNext > 0)
            {
                direction /= distanceToNext;
            }

            // Move the enemy
            sprite.move(direction * speed * deltaTime);

            // Check if the enemy has reached the current waypoint
            if (distance(position, target) < speed * deltaTime)
            {
                currentWaypoint++;
            }
        }
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(sprite);
    }

private:
    sf::Sprite sprite;
    std::vector<sf::Vector2f> path;
    size_t currentWaypoint;
    float speed;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "TD");

    // Load background texture
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    if (!backgroundTexture.loadFromFile("valjdaZadnjaRepo\\images\\terrain_with_curve.png"))
    {
        std::cerr << "Error loading background image!\n";
        return -1;
    }
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    backgroundSprite.setScale(scaleX, scaleY);
    backgroundSprite.setPosition(0, 0);

    // Load tower stand texture and set positions
    sf::Texture standTexture;
    std::vector<sf::Sprite> standSprites;
    if (!standTexture.loadFromFile("valjdaZadnjaRepo\\images\\terrain_with_curve.png"))
    {
        std::cerr << "Error loading stand image!\n";
        return -1;
    }
    sf::Vector2f positions[] = {{500, 215}, {440, 570}, {930, 660}, {930, 970}};
    for (auto &position : positions)
    {
        sf::Sprite standSprite;
        standSprite.setTexture(standTexture);
        standSprite.setScale(150.f / standTexture.getSize().x, 100.f / standTexture.getSize().y);
        standSprite.setPosition(position);
        standSprites.push_back(standSprite);
    }

    // Define path for enemy
    std::vector<sf::Vector2f> path = {
        {0, 324},
        {630, 324},
        {630, 775},
        {1920, 775}};

    // Load enemy texture and create enemy
    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("valjdaZadnjaRepo\\images\\terrain_with_curve.png"))
    {
        std::cerr << "Error loading enemy image!\n";
        return -1;
    }
    sf::Vector2f enemyScale(0.2f, 0.2f); // Example scale, adjust as needed
    Enemy enemy(enemyTexture, path, enemyScale);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        // Update enemy position
        enemy.update(deltaTime);

        // Draw everything
        window.clear();
        window.draw(backgroundSprite);
        for (auto &standSprite : standSprites)
            window.draw(standSprite);
        enemy.draw(window);
        window.display();
    }

    return 0;
}
