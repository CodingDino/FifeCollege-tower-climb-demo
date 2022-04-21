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

    bool IsColliding(GameObject& other);
    sf::Vector2f GetCollisionDepth(GameObject& other);

    sf::Sprite objectSprite;
    sf::FloatRect modifiedCollider;

private:

    sf::Vector2f position;


};

