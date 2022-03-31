#pragma once
#include "SFML/Graphics.hpp"


class GameObject
{

public:

    GameObject();

    void Draw(sf::RenderTarget& target);
    virtual void Update(sf::Time frameTime);

    void SetPosition(sf::Vector2f newPos);
    sf::Vector2f GetPosition();
    sf::FloatRect GetCollider();

protected:

    sf::Sprite objectSprite;

private:

    sf::Vector2f position;


};

