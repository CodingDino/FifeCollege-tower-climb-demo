#include "Player.h"

sf::Texture* Player::playerTexture = nullptr;

Player::Player()
	: GameObject	()
	, MOVE_SPEED	(100)
	, velocity		(0, 0)
{
	if (playerTexture == nullptr)
	{
		playerTexture = new sf::Texture();
		playerTexture->loadFromFile("Assets/Graphics/Player.png");
	}

	objectSprite.setTexture(*playerTexture);
}

void Player::Update(sf::Time frameTime)
{
	// Check for player inputs
	velocity.x = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		velocity.x = -MOVE_SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		velocity.x = MOVE_SPEED;

	// Update position based on velocity
	SetPosition(GetPosition() + velocity * frameTime.asSeconds());

	// Call parent update
	GameObject::Update(frameTime);

}
