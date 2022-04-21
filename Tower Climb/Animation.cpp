#include "Animation.h"

Animation::Animation()
	: frames			()
	, sprite			(nullptr)
	, playBackSpeed		(15.0f)
	, loop				(true)
	, nextFrameChange	()
	, currentFrame		(0)
	, playing			(true)
{
}

void Animation::AddFrame(sf::Texture* newFrame)
{
	if (newFrame)
		frames.push_back(newFrame);
}

void Animation::SetSprite(sf::Sprite* newSprite)
{
	sprite = newSprite;
}

void Animation::SetPlayBackSpeed(float newPlayBackSpeed)
{
	playBackSpeed = newPlayBackSpeed;
}

void Animation::SetLoop(bool newLoop)
{
	loop = newLoop;
}

bool Animation::GetPlaying()
{
	return playing;
}

void Animation::Update(sf::Time frameTime)
{
	// Only process the animation if it is set to be playing
	if (playing)
	{
		// Subtract the time passed from our time until the next frame change
		nextFrameChange -= frameTime;
		// Determine if it is time to change frames
		if (nextFrameChange.asSeconds() <= 0)
		{
			// If it is time to change frames,
			// Change the sprite's texture to the next texture in the list
			++currentFrame;

			// Check if we reached the end of the animation
			if (currentFrame >= frames.size())
			{
				// Should we loop?
				if (loop)
				{
					// Looping
					// Reset the animation
					// SHow the FIRST frame
					currentFrame = 0;
				}
				else
				{
					// NOT loop
					// Show the LAST frame
					currentFrame = frames.size() - 1;

					playing = false;
				}
			}

			// Update sprite to show correct new frame
			if (sprite)
			{
				sprite->setTexture(*frames[currentFrame]);
			}

			// Determine the time for the next frame change
			// Convert our frames per second to seconds per frame
			float timeToChange = 1.0f / playBackSpeed;
			nextFrameChange = sf::seconds(timeToChange);
		}
	}
}

void Animation::Play()
{
	playing = true;

	// Update sprite to show correct new frame
	if (sprite)
	{
		sprite->setTexture(*frames[currentFrame]);
	}
}

void Animation::Pause()
{
	playing = false;
}

void Animation::Stop()
{
	// Stop playing
	playing = false;

	// Reset animation to start of the animation
	currentFrame = 0;

	// Update sprite to show correct new frame
	if (sprite)
	{
		sprite->setTexture(*frames[currentFrame]);
	}

	// Make sure we spend the full time on that first frame when we play again
	float timeToChange = 1.0f / playBackSpeed;
	nextFrameChange = sf::seconds(timeToChange);
}
