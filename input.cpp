#include "./libs/input.hpp"

Input::Input()
{
    button.up = button.left = button.right = button.run = button.attack = button.down = button.jump = button.heal = false;
}

void Input::handleInput(Event& event)
{
    if(event.type == Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case Keyboard::Right:
            button.right = true;
            break;
        case Keyboard::Left:
            button.left = true;
            break;
        case Keyboard::Up:
            button.up = true;
            break;
        case Keyboard::Down:
            button.down = true;
            break;        
        case Keyboard::Space:
            button.jump = true;
            break;        
        case Keyboard::A:
            button.attack = true;
            break;
        case Keyboard::X:
            button.run = true;
            break;
        case Keyboard::W:
            button.heal = true;
            break;                      
        default:
            break;
        }
    }

    if(event.type == Event::KeyReleased)
    {
        switch (event.key.code)
        {
        case Keyboard::Right:
            button.right = false;
            break;
        case Keyboard::Left:
            button.left = false;
            break;
        case Keyboard::Up:
            button.up = false;
            break;
        case Keyboard::Down:
            button.down = false;
            break;        
        case Keyboard::Space:
            button.jump = false;
            break;        
        case Keyboard::A:
            button.attack = false;
            break;
        case Keyboard::X:
            button.run = false;
            break;
        case Keyboard::W:
            button.heal = false;
            break;                      
        default:
            break;
        }
    }
}

Button Input::getButton(void) const
{
    return button;
}