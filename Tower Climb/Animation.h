#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Animation
{
public:

	// Constructors/Destructors
	Animation();

	// Getters/Setters etc
	void AddFrame(sf::Texture* newFrame);
	void SetSprite(sf::Sprite* newSprite);
	void SetPlayBackSpeed(float newPlayBackSpeed);
	void SetLoop(bool newLoop);
	bool GetPlaying();

	// Processing and Controls
	void Update(sf::Time frameTime);
	void Play();
	void Pause();
	void Stop();

private:

	// Settings
	std::vector<sf::Texture*> frames;
	sf::Sprite* sprite;
	float playBackSpeed;
	bool loop;

	// State
	sf::Time nextFrameChange;
	int currentFrame;
	bool playing;
};

