#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    // Create the main window
    RenderWindow app(VideoMode(800, 600), "Raid");



    // Load a sprite to display
    Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    Sprite sprite(texture);

    int positionX = sprite.getPosition().x;
    int positionY = sprite.getPosition().y;

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                app.close();

            if(Keyboard::isKeyPressed(Keyboard::D)){
                positionX += 20;
                sprite.setPosition(positionX, positionY);
            }

            if(Keyboard::isKeyPressed(Keyboard::A)){
                positionX -= 20;
                sprite.setPosition(positionX, positionY);
            }

            if(Keyboard::isKeyPressed(Keyboard::W)){
                positionY -= 20;
                sprite.setPosition(positionX, positionY);
            }

            if(Keyboard::isKeyPressed(Keyboard::S)){
                positionY += 20;
                sprite.setPosition(positionX, positionY);
            }
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sprite);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

