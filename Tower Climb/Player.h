#pragma once
#include "GameObject.h"


class Player :
    public GameObject
{

public:

    Player();

    virtual void Update(sf::Time frameTime) override;

    void Jump();

private:

    static sf::Texture* playerTexture;

    const float MOVE_SPEED;
    const float JUMP_SPEED;
    const float GRAVITY;
    sf::Vector2f velocity;

};

