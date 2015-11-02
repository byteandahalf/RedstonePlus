#pragma once
class MinecraftClient;
class TileEntityRenderer;
class TileEntityRendererId;
class PistonRenderer;
class Textures;

class TileEntityRenderDispatcher {
public:
	MinecraftClient& minecraft;
	Textures* textures;
	
	static PistonRenderer* pistonRenderer;
};
