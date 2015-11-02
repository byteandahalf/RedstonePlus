#pragma once
#include "Tile.h"
#include <memory>
class TileEntity;
class TilePos;
class TileSource;

class EntityTile : public Tile {
public:
	virtual std::unique_ptr<TileEntity> newTileEntity(const TilePos&);
	virtual void neighborChanged(TileSource*, int, int, int, int, int, int);
	virtual void triggerEvent(TileSource*, int, int, int, int, int);

	EntityTile(int, const Material*);
	EntityTile(int, const std::string&, const Material*);
};
