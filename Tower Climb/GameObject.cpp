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

sf::FloatRect GameObject::GetCollider()
{
	sf::FloatRect collider = modifiedCollider;
	collider.left += position.x;
	collider.top += position.y;
	return collider;
}

bool GameObject::IsColliding(GameObject& other)
{
	sf::FloatRect myCollider = GetCollider();
	sf::FloatRect otherCollider = other.GetCollider();

	return myCollider.intersects(otherCollider);
}

sf::Vector2f GameObject::GetCollisionDepth(GameObject& other)
{
	sf::FloatRect myCollider = GetCollider();
	sf::FloatRect otherCollider = other.GetCollider();

	sf::Vector2f myPosition(myCollider.left, myCollider.top);
	sf::Vector2f otherPosition(otherCollider.left, otherCollider.top);

	sf::Vector2f myWidthHeight(myCollider.width, myCollider.height);
	sf::Vector2f otherWidthHeight(otherCollider.width, otherCollider.height);

	sf::Vector2f myCentre = myPosition + 0.5f * myWidthHeight;
	sf::Vector2f otherCentre = otherPosition + 0.5f * otherWidthHeight;

	sf::Vector2f distance = otherCentre - myCentre;
	sf::Vector2f minDistance = 0.5f * myWidthHeight + 0.5f * otherWidthHeight;

	if (distance.x < 0)
		minDistance.x = -minDistance.x;
	if (distance.y < 0)
		minDistance.y = -minDistance.y;

	sf::Vector2f depth = minDistance - distance;

	return depth;
}
