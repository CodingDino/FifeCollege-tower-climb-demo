#include "Platform.h"
#include "Player.h"

sf::Texture* Platform::platformTexture = nullptr;

Platform::Platform()
	: Block()
{

	if (platformTexture == nullptr)
	{
		platformTexture = new sf::Texture();
		platformTexture->loadFromFile("Assets/Graphics/Platform.png");
	}

	objectSprite.setTexture(*platformTexture);

	// Set up platform collider
	modifiedCollider.left = 0;
	modifiedCollider.top = 0;
	modifiedCollider.width = 150;
	modifiedCollider.height = 32;
}

void Platform::HandleCollision(GameObject& other)
{

	// Check if the thing we are checking is actually a player
	Player* checkPlayer = dynamic_cast<Player*>(&other);

	if (checkPlayer == nullptr)
		return; // Exit check early because we don't care if we ran into something other than a player

	// If it was, check if we collided with it
	if (!IsColliding(other))
		return; // We're not colliding so we don't care

	// If we did, get the collision depth
	sf::Vector2f depth = GetCollisionDepth(other);
	sf::Vector2f absDepth = sf::Vector2f(abs(depth.x), abs(depth.y));
	sf::Vector2f playerPosition = checkPlayer->GetPosition();

	// Use the collision depth to move the player out of the platform
	if (absDepth.x < absDepth.y) // we hit the side of the platform
	{
		// Move them along the x direction
		playerPosition.x += depth.x;
		checkPlayer->SetPosition(playerPosition);
	}
	else // They hit the top or bottom of the platform
	{
		// Move them along the y direction
		playerPosition.y += depth.y;
		checkPlayer->SetPosition(playerPosition);

		// If the player hit the top of the platform, make them jump
		if (playerPosition.y < GetPosition().y)
		{
			checkPlayer->Jump();
		}
	}


}
