#pragma once
#include "GameObject.h"
#include "Animation.h"

class AnimatingObject :
    public GameObject
{

public:

    AnimatingObject();

    // Setup
    Animation* CreateAnimation(std::string name);

    // Controls
    void Play();
    void Play(std::string newAnimation);
    void Pause();
    void Stop();

    // Processing
    virtual void Update(sf::Time frameTime) override;

private:

    std::map<std::string, Animation> animations;
    Animation* currentAnimation;

};

