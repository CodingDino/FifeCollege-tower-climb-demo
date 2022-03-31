#include "Player.h"

sf::Texture* Player::playerStand = nullptr;
sf::Texture* Player::playerJump = nullptr;

Player::Player()
	: AnimatingObject	()
	, MOVE_SPEED		(100)
	, JUMP_SPEED		(500)
	, GRAVITY			(1000)
	, velocity			(0, 0)
{
	if (playerStand == nullptr)
	{
		playerStand = new sf::Texture();
		playerStand->loadFromFile("Assets/Graphics/PlayerStand.png");
	}
	if (playerJump == nullptr)
	{
		playerJump = new sf::Texture();
		playerJump->loadFromFile("Assets/Graphics/PlayerJump.png");
	}

	objectSprite.setTexture(*playerStand);

	// Create the animation
	Animation* jump = CreateAnimation("jump");
	jump->AddFrame(playerStand);
	jump->AddFrame(playerJump);
	jump->SetPlayBackSpeed(10);
	jump->SetLoop(false);

	Play("Jump");
}

void Player::Update(sf::Time frameTime)
{
	// Check for player inputs
	velocity.x = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		velocity.x = -MOVE_SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		velocity.x = MOVE_SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		Jump();

	// Update velocity based on gravity
	velocity.y += GRAVITY * frameTime.asSeconds();

	// Update position based on velocity
	SetPosition(GetPosition() + velocity * frameTime.asSeconds());

	// Call parent update
	AnimatingObject::Update(frameTime);

}

void Player::Jump()
{
	velocity.y = -JUMP_SPEED;
	Play("Jump");
}


