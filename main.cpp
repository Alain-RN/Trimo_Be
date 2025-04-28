#include "./libs/main.hpp"

float animationSpeed = 0.1f;
float elapsedTime = 0.0f;
bool isHealing = true;

int iFrame = 0;
void playAnimation(Sprite& player, int nbrFrame);
void actionStart(Sprite& player, GameTexture playerTexture);

int main()
{
    RenderWindow window(VideoMode(800, 600), "Trimobe marche !");

    // window.setFramerateLimit(60);
    GameTexture playerWalkTexture("./res/walking.png");

    GameTexture playerHealTexture("./res/healing.png");

    GameTexture playerPauseTexture("./res/pause.png");

    Player playerTest(
        /* walk Texture  */ playerWalkTexture.getTexture(),
        /* Pause Texture */ playerPauseTexture.getTexture(),
        /* Speed         */ 0.1f
    );

    playerTest.getSprite().setOrigin(playerTest.getSprite().getLocalBounds().width, 0);

    playerTest.walkLeft();


    Sprite player(playerPauseTexture.getTexture());

    player.setTextureRect(IntRect(64 * iFrame, 28, 64, 68));

    player.setOrigin(player.getLocalBounds().width, 0);

    player.setPosition( 40, 100);

    Clock clock;
    bool allerGauche = false;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        elapsedTime += deltaTime;



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            allerGauche = true;
            player.setScale(-1.f, 1.f); // Tourner vers la gauche
            player.move(-0.1f, 0.f);    // Bouger vers la gauche
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            allerGauche = false;
            player.setScale(1.f, 1.f); // Normal vers la droite
            player.move(0.1f, 0.f);    // Bouger vers la droite
        }



        
        // actionStart(player, playerPauseTexture);

        window.clear();
        window.draw(player);
        // window.draw(playerTest.getSprite());
        window.display();
    }

    return 0;
}

void playAnimation(Sprite& sptite, int nbrFrame)
{
    if (elapsedTime >= animationSpeed)
    {
        if (iFrame != nbrFrame)
        {
            sptite.setTextureRect(IntRect(64 * iFrame, 28, 64, 68));
            iFrame++;
        }
        else
        {
            iFrame = 0;
        }
        elapsedTime = 0.0f;
    }
}

void actionStart(Sprite& player, GameTexture playerTexture)
{
    if(isHealing)
    {
        if(iFrame != playerTexture.getFrame())
        {
            playAnimation(player, playerTexture.getFrame());
        }
        else
        {
            isHealing = false;
        }
    }
}