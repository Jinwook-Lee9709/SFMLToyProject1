#include "stdafx.h"

int main()
{
  /*  sf::VideoMode vm(1600, 900);
    sf::RenderWindow window(vm, "Slay the Spire", sf::Style::Default);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2f cnterPos = (sf::Vector2f)(windowSize / 2u);

    sf::Texture texBackgrpud;
    sf::Texture texcancel;
    sf::Texture texDeck;
    sf::Texture texGrave;
    texBackgrpud.loadFromFile("graphics/Background.png");
    texcancel.loadFromFile("graphics/cancel.png");
    texDeck.loadFromFile ("graphics/Deck.png");
    texGrave.loadFromFile("graphics/Grave.png");
    sf::Sprite spriteBackground;
    spriteBackground.setTexture(texBackgrpud);
    sf::Sprite spritecancel;
    spritecancel.setTexture(texcancel);
    sf::Sprite spriteDeck;
    spriteDeck.setTexture(texDeck);
    sf::Sprite spriteGrave;
    spriteGrave.setTexture(texGrave);
    











    window.clear();
    window.draw(spriteBackground);
    window.draw(spritecancel);
    window.draw(spriteDeck);
    window.draw(spriteGrave);
    window.display();*/
    
    
    
    
    
    FRAMEWORK.Init(1600, 900, "SFML!");
    FRAMEWORK.Do();
    FRAMEWORK.Release();
    return 0;


    
}