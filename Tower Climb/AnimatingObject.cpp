#include "AnimatingObject.h"


AnimatingObject::AnimatingObject()
	: GameObject			()
	, m_animations			()
	, m_currentAnimation	(nullptr)
{

}

Animation* AnimatingObject::CreateAnimation(std::string _name)
{
	Animation* newAnimation = &(m_animations[_name]);
	newAnimation->SetSprite(objectSprite);
	return newAnimation;
}

void AnimatingObject::Play(std::string _newAnimation)
{
	Stop();

	m_currentAnimation = &m_animations[_newAnimation];
	
	Play();
}

void AnimatingObject::Play()
{
	if (m_currentAnimation)
		m_currentAnimation->Play();
}

void AnimatingObject::Pause()
{
	if (m_currentAnimation)
		m_currentAnimation->Pause();
}

void AnimatingObject::Stop()
{
	if (m_currentAnimation)
		m_currentAnimation->Stop();
}

void AnimatingObject::Update(sf::Time _frameTime)
{
	if (m_currentAnimation)
		m_currentAnimation->Update(_frameTime);
}