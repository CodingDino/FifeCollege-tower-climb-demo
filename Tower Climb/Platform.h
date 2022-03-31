#pragma once
#include "Block.h"
class Platform :
    public Block
{

public:

    Platform();

    virtual void HandleCollision(GameObject& other) override;

private:

    static sf::Texture* platformTexture;
};

