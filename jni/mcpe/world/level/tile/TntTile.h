#pragma once

#include "Tile.h"

class TntTile : public Tile {
public:
	virtual void destroy(TileSource*, int, int, int, int, Entity*);
	virtual void onPlace(TileSource*, int, int, int);
	virtual void _neighborChanged(TileSource*, int, int, int, int, int, int);
};
