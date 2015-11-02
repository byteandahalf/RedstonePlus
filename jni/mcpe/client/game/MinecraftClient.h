#pragma once
#include <memory>
class LevelRenderer;
class Player;

class MinecraftClient {
public:
	char filler[152];
	std::unique_ptr<LevelRenderer> levelRenderer;
	
	Player* getLocalPlayer();
};
