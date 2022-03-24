#pragma once
#include "GameObject.h"
#include "Animation.h"


class AnimatingObject :
    public GameObject
{
public:

	AnimatingObject();

	// Setup
	Animation* CreateAnimation(std::string _name);

	// Controls
	void Play();
	void Play(std::string _newAnimation);
	void Pause();
	void Stop();

	// Processing
	void Update(sf::Time _frameTime);

private:

	// Settings
	std::map<std::string, Animation> m_animations;

	// State
	Animation* m_currentAnimation;
};

