#include "AnimatingObject.h"

AnimatingObject::AnimatingObject()
	: GameObject		()
	, animations		()
	, currentAnimation	(nullptr)
{
}

Animation* AnimatingObject::CreateAnimation(std::string name)
{
	Animation* newAnimation = &(animations[name]);
	newAnimation->SetSprite(&objectSprite);
	return newAnimation;
}

void AnimatingObject::Play()
{
	if (currentAnimation)
		currentAnimation->Play();
}

void AnimatingObject::Play(std::string newAnimation)
{
	// What if our current animation is the one we're trying to play?
	// This would stop it, so we'd constantly be on frame 1
	// Could add an if check to ensure the new animation is different from the current one
	Stop();

	// This animation may not exist, we should check that before accessing the map
	currentAnimation = &(animations[newAnimation]);

	Play();
}

void AnimatingObject::Pause()
{
	if (currentAnimation)
		currentAnimation->Pause();
}

void AnimatingObject::Stop()
{
	if (currentAnimation)
		currentAnimation->Stop();
}

void AnimatingObject::Update(sf::Time frameTime)
{
	GameObject::Update(frameTime);

	if (currentAnimation)
		currentAnimation->Update(frameTime);
}
