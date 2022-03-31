#include "Platform.h"
#include "Player.h"

sf::Texture* Platform::platformTexture = nullptr;

Platform::Platform()
{
    if (platformTexture == nullptr)
    {
        platformTexture = new sf::Texture();
        platformTexture->loadFromFile("Assets/Graphics/Platform.png");
    }

    objectSprite.setTexture(*platformTexture);
}

void Platform::HandleCollision(GameObject& other)
{
	// Check if the thing we collided with was a player
	Player* hitPlayer = dynamic_cast<Player*>(&other);

	// If it wasn't a player, exit early.
	if (hitPlayer == nullptr)
		return;

	// Get the two colliders
    sf::FloatRect playerCollider = hitPlayer->GetCollider();
    sf::FloatRect platformCollider = GetCollider();

    sf::Vector2f playerPosition(playerCollider.left, playerCollider.top);

    // Check for collision
    bool colliding = playerCollider.intersects(platformCollider);

    if (colliding)
    {
        // Collision Depth
        sf::Vector2f PlayerWidthHeight = sf::Vector2f(playerCollider.width, playerCollider.height);
        sf::Vector2f PlatformWidthHeight = sf::Vector2f(platformCollider.width, platformCollider.height);

        sf::Vector2f PlayerCentre = sf::Vector2f(playerCollider.left, playerCollider.top);
        PlayerCentre += 0.5f * PlayerWidthHeight;
        sf::Vector2f PlatformCentre = sf::Vector2f(platformCollider.left, platformCollider.top);
        PlatformCentre += 0.5f * PlatformWidthHeight;

        sf::Vector2f distance = PlatformCentre - PlayerCentre;
        sf::Vector2f minDistance = 0.5f * PlayerWidthHeight + 0.5f * PlatformWidthHeight;
        if (distance.x < 0)
            minDistance.x = -minDistance.x;
        if (distance.y < 0)
            minDistance.y = -minDistance.y;

        sf::Vector2f depth = minDistance - distance;
        sf::Vector2f absDepth = sf::Vector2f(abs(depth.x), abs(depth.y));

        if (absDepth.x < absDepth.y)
        {
            // Move along x direction
            playerPosition.x -= depth.x;
        }
        else
        {
            // Move along y direction
            playerPosition.y -= depth.y;

            // Falling onto block from above?
            if (playerPosition.y < platformCollider.top)
                // Make player jump!
                hitPlayer->Jump();
        }

        // Update player position
        hitPlayer->SetPosition(playerPosition);
    }	

}
