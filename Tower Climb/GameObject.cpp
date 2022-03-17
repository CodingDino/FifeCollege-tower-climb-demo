#include "GameObject.h"

GameObject::GameObject()
	: objectSprite	()
	, position		(0,0)
{
}

void GameObject::Draw(sf::RenderTarget& target)
{
	target.draw(objectSprite);
}

void GameObject::Update(sf::Time frameTime)
{
}

void GameObject::SetPosition(sf::Vector2f newPos)
{
	position = newPos;
	objectSprite.setPosition(newPos);
}

sf::Vector2f GameObject::GetPosition()
{
	return position;
}
