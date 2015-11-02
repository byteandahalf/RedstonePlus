#pragma once

#include <string>
#include <map>
#include <memory>

#include "../../TilePos.h"
#include "../../../phys/AABB.h"
#include "../../../phys/Vec3.h"
#include "TileEntityType.h"
class TileSource;
class Tile;
class CompoundTag;
class Entity;

class TileEntity {
public:
	static std::map<std::string, TileEntityType> idClassMap;
	static std::map<TileEntityType, std::string> classIdMap;
	static int _runningId;

	TilePos pos; // 4
	AABB bb; // 16
	int data; // 44
	TileEntityType type; // 48
	int runningId; // 52
	bool clientSideOnly; // 56
	int rendererId; // 60
	Tile* tile; // 64
	bool removed; // 68
	float destroyTime; // 72
	Vec3 destroyDirection; // 76
	bool changed; // 88

	TileEntity(TileEntityType, const TilePos&, const std::string&);

	virtual ~TileEntity();
	virtual void load(CompoundTag*); // loadFromNBT
	virtual bool save(CompoundTag*); // writeToNBT
	virtual void tick(TileSource*); // updateEntity
	virtual bool isFinished(); // isInvalid
	virtual void onChanged(TileSource*); // onInventoryChanged
	virtual void* getUpdatePacket(TileSource&); // getDescriptionPacket
	virtual void onUpdatePacket(CompoundTag*);
	virtual void onRemoved();
	virtual void triggerEvent(int, int); // receiveClientEvent
	virtual void clearCache(); // updateContainingBlockInfo
	virtual void onNeighborChanged(TileSource&, int, int, int);
	virtual float getShadowRadius(TileSource&) const;
	virtual Entity* getCrackEntity(TileSource&, TilePos const&);

	void setChanged();
	const Vec3& distanceToSqr(const Vec3&); // getDistanceFrom

	static void initTileEntities(); // static {}
	static void loadStatic(CompoundTag&); // createAndLoadEntity
	static void setId(TileEntityType, const std::string&); // func_145826_a
};

class TileEntityFactory {
public:
	std::unique_ptr<TileEntity> createTileEntity(TileEntityType, const TilePos&);
};
