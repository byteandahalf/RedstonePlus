#pragma once

#include "mcpe/CommonTypes.h"
#include "TileTickingQueue.h"
#include "../entity/Entity.h"
#include "TilePos.h"
class Tile;
class AABB;
class Level;
class TileEntity;

class TileSource {
public:
	Level* getLevel() const;

	void updateNeighborsAt(const TilePos&, TileID);
	FullTile getTile(int, int, int);
	Tile* getTilePtr(int, int, int);
	DataID getData(int, int, int);
	bool setTileAndData(int, int, int, FullTile, int);
	void removeTile(int, int, int);
	void tileEvent(int, int, int, int, int);
	TileEntity* getTileEntity(const TilePos&);
	void fireTilesDirty(int, int, int, int, int, int);
	TileTickingQueue* getTickQueue(TilePos const&);
	EntityList& getEntities(Entity*, AABB const&);

	void scheduleBlockUpdate(int, int, int, int, int);
	bool isBlockIndirectlyGettingPowered(int, int, int);
	int isBlockProvidingPowerTo(int, int, int, int);
	int getIndirectPowerLevelTo(int, int, int, int);
	int getBlockPowerInput(int, int, int);
	bool getIndirectPowerOutput(int, int, int, int);
	bool isBlockGettingPowered(int, int, int);
	int getStrongestIndirectPower(int, int, int);
	bool isRedstonePlacementException(int, int, int);
};
