#pragma once
#include "../renderer/EntityShaderManager.h"
#include <string>
#include <memory>
class TileEntityRenderDispatcher;
class Level;
class TileSource;
class TileEntity;
class Vec3;
namespace mce { class MaterialPtr; };

class TileEntityRenderer : public EntityShaderManager {
public:
	char filler[40];
	TileEntityRenderDispatcher* dispatcher;
	
	TileEntityRenderer();
	
	virtual ~TileEntityRenderer();
	virtual void render(TileSource&, TileEntity&, const Vec3&, float, const mce::MaterialPtr&, const std::string&, int) = 0;
	virtual void* onNewLevel(Level*);
	
	void init(TileEntityRenderDispatcher*);
};
