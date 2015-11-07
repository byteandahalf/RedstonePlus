#pragma once
struct BlockID;
struct DataID;
class Block;
class Dimension;
struct BlockPos;
class EntityList;
#include "../entity/Entity.h"
#include "BlockTickingQueue.h"

class BlockSource {
public:
	Level* getLevel() const;
	void updateNeighborsAt(const BlockPos&, BlockID);
	bool isTopSolidBlocking(const BlockPos&);
	bool isConsideredSolidBlock(const BlockPos&);
	Block* getBlock(const BlockPos&);
	FullBlock getBlockID(const BlockPos&);
	DataID getData(const BlockPos&);
	bool setBlockAndData(const BlockPos&, FullBlock, int);
	void removeBlock(const BlockPos&);
	void blockEvent(const BlockPos&, int, int);
	BlockEntity* getBlockEntity(const BlockPos&);
	void fireBlocksDirty(int, int, int, int, int, int);
	EntityList& getEntities(Entity*, const AABB&);
	Dimension* getDimension();
	BlockTickingQueue* getTickQueue(const BlockPos&);

	void sheduleBlockUpdate(const BlockPos&, int, int);
};
