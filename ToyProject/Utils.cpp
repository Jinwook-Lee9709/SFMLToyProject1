#include "stdafx.h"
#include "Utils.h"

sf::Vector2f Utils::SetOrigin(sf::Sprite& obj, Origins preset)
{
    sf::FloatRect rect = obj.getLocalBounds();
    sf::Vector2f newOrigin(rect.width, rect.height);
    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    obj.setOrigin(newOrigin);

    return newOrigin;
}

sf::Vector2f Utils::SetOrigin(sf::Text& text, Origins preset)
{
    sf::FloatRect rect = text.getLocalBounds();
    sf::Vector2f newOrigin(rect.width, rect.height);
    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    text.setOrigin(newOrigin);

    return newOrigin;
}

sf::String Utils::makeCardText(Cards card, int atk)
{
    switch (card) {
    case Cards::Bash: {
        return "    Deal " + std::to_string(8 + atk) + " Damage.\n Apply 2 Vulnerable";
    }
    case Cards::Strike: {
        return "Deal " + std::to_string(6 + atk) + " Damage.";
    }
    case Cards::Inflame: {
        return "Gain 2 Strength";
    }

    case Cards::Defend: {
        return "Gain 5 Block";
    }
    }
}
