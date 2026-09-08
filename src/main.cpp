#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Shimera - SFML3");

    if (!window.setActive(true)) {
        std::cerr << "[SFML] failed to activate the window!" << '\n';
        return -1;
    }

    // When using Shimera, don't forget to initialize GLEW
    // if (glewInit() != GLEW_OK) {
    //     std::cerr << "[GLEW] initialization failed!" << '\n';
    //     return -1;
    // }

    window.setFramerateLimit(60);

    // Create a Backend

    // Create a Framebuffer

    // Create a new instance of EffectPipeline

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

        if (!window.setActive(true)) {
            break;
        }

        // Create the SFML's Render Texture, it is used to render the scene inside it, and then rendered in 2D on the Quad Post Processing.
        // auto *sfmlRenderTexture = static_cast<sf::RenderTexture*>(sceneFramebuffer->getNativeRenderTarget());

        // You need to draw the scene between our framebuffer bind and unbind

        window.clear(background); // Replace this with the sfmlRenderTexture clear
        window.draw(square); // Replace this with the sfmlRenderTexture draw

        // window.setActive(true);
        // glClear(GL_COLOR_BUFFER_BIT);
        // Add the EffectPipeline render

        window.display();
    }

    // Delete the Framebuffer
    // Delete the Backend

    return 0;
}
