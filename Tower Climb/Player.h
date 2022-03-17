#pragma once
#include "GameObject.h"


class Player :
    public GameObject
{

public:

    Player();

    virtual void Update(sf::Time frameTime) override;

private:

    static sf::Texture* playerTexture;

    const float MOVE_SPEED;
    sf::Vector2f velocity;

};

