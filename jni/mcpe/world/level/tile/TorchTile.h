#pragma once

#include "Tile.h"


class TorchTile : public Tile {
public:
	TorchTile(int, const std::string&);

	virtual ~TorchTile();
	virtual const AABB& getVisualShape(TileSource*, int, int, int, AABB&, bool);
	virtual AABB* getAABB(TileSource*, int, int, int, AABB&, int, bool, int);
	virtual bool mayPlace(TileSource*, int, int, int);
	virtual void tick(TileSource*, int, int, int, Random*);
	virtual void animateTick(TileSource*, int, int, int, Random*);
	virtual void neighborChanged(TileSource*, int, int, int, int, int, int);
	virtual void onPlace(TileSource*, int, int, int);
	virtual int getPlacementDataValue(Mob*, int, int, int, signed char, float, float, float, int);
	virtual int getIconYOffset() const;
};
