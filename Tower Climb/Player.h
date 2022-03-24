#pragma once
#include "AnimatingObject.h"


class Player :
    public AnimatingObject
{

public:

    Player();

    virtual void Update(sf::Time frameTime) override;

    void Jump();

private:

    static sf::Texture* playerStand;
    static sf::Texture* playerJump;

    const float MOVE_SPEED;
    const float JUMP_SPEED;
    const float GRAVITY;
    sf::Vector2f velocity;

};

