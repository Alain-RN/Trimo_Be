#ifndef INPUT
#define INPUT

#include <SFML/Graphics.hpp>

using namespace sf;

struct Button
{
    bool left, right, jump, up, down, attack, run, heal;
};


class Input
{
private:
    Button button;
public:
    Input();
    void handleInput(Event& event);
};



#endif