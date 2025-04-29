#include "./libs/main.hpp"

float animationSpeed = 0.041f;
float elapsedTime = 0.0f;
int iFrame = 0;

GameTexture playerWalkTexture("./res/walking.png");
GameTexture playerHealTexture("./res/healing.png");
GameTexture playerPauseTexture("./res/pause.png");

Input inputGame;

Player playerTest(
/* walk Texture  */ playerWalkTexture.getTexture(),
/* Pause Texture */ playerPauseTexture.getTexture(),
/* Speed         */ 0.1f
);

RectangleShape hitbox;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Trimobe marche !");

    Font font;
    if(!font.loadFromFile("./res/font/JungleAdventurer.ttf"))
        return - 1;
    Text text;

    text.setFont(font);
    text.setCharacterSize(60);
    text.setString("TrimobE");

    text.setPosition(300, 400);

    hitbox.setSize(sf::Vector2f(29.f, 68.5f));
    hitbox.setOrigin(hitbox.getSize().x / 2, hitbox.getSize().y / 2);
    hitbox.setFillColor(sf::Color(255, 0, 0));

    // window.setFramerateLimit(60);

    hitbox.setPosition(playerTest.getSprite().getPosition().x - 4, playerTest.getSprite().getPosition().y);


    Sprite player(playerPauseTexture.getTexture());
    player.setOrigin(player.getLocalBounds().width / 2, 0);
    player.setPosition( 800, 100);

    Clock clock;

    RectangleShape obs(Vector2f(200, 300));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            inputGame.handleInput(event);
        }

        float deltaTime = clock.restart().asSeconds();
        elapsedTime += deltaTime;

        checkButton(iFrame);

        if (elapsedTime >= animationSpeed)
        {
            if (iFrame != 12)
            {
                iFrame++;
            }
            else
            {
                iFrame = 0;
            }
            elapsedTime = 0.0f;
        }

        if(hitbox.getGlobalBounds().intersects(obs.getGlobalBounds()))
        {
            text.setString("TrimobEeeeeeeeeeeee");
        } else {
            text.setString("Trim");
        }

        window.clear();
        window.draw(hitbox);
        window.draw(playerTest.getSprite());
        window.draw(obs);
        window.draw(text);

        window.display();
    }

    return 0;
}

void checkButton(int iFrame)
{
    if (inputGame.getButton().left)
    {
        playerTest.walkLeft(iFrame);
        playerTest.getSprite().move(-0.03f, 0.f);
        hitbox.setPosition(playerTest.getSprite().getPosition().x + 4, playerTest.getSprite().getPosition().y);
    }
    else if (inputGame.getButton().right)
    {
        playerTest.walkRight(iFrame);
        playerTest.getSprite().move(0.03f, 0.f);
        hitbox.setPosition(playerTest.getSprite().getPosition().x - 4, playerTest.getSprite().getPosition().y);
    }
    else {
        playerTest.pause();
    }
}