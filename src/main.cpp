#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Shimera - SFML3");
    window.setFramerateLimit(60);

    const sf::Color background(128, 128, 128);

    sf::RectangleShape square({200.f, 200.f});
    square.setFillColor(sf::Color::Yellow);
    square.setOrigin(square.getSize() / 2.f);
    square.setPosition(sf::Vector2f(window.getSize()) / 2.f);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(background);
        window.draw(square);
        window.display();
    }

    return 0;
}
