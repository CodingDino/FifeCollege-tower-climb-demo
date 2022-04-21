#pragma once
#include "GameObject.h"
class Block :
    public GameObject
{

public:

    Block();

    virtual void HandleCollision(GameObject& other);

};

