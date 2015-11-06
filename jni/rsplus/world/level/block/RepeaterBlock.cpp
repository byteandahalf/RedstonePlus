#include "RepeaterBlock.h"
#include "mcpe/world/material/Material.h"
#include "mcpe/world/phys/Vec3.h"
/*#include "mcpe/world/level/TileSource.h"
#include "mcpe/world/level/Level.h"
#include "mcpe/world/Facing.h"
#include "mcpe/world/item/Item.h"
#include "mcpe/world/entity/player/Player.h"
#include "mcpe/util/Mth.h"*/
#include <cmath>

class BlockPos {
public:
	int x, y, z;
};

float RepeaterBlock::torchOffset[4] = {-0.0625F, 0.0625F, 0.1875F, 0.3125F};
int RepeaterBlock::delaySettings[4] = {1, 2, 3, 4};

RepeaterBlock::RepeaterBlock(int blockId, const std::string& texture, bool powered) : Block("diode", blockId, texture, Material::mMaterials[28]) {
    init();
    side_texture = getTextureUVCoordinateSet("stone_slab", 0);
    renderType = 0;
    renderLayer = 7;
	creativeCategory = 3;
    setSolid(false);
    setVisualShape({0.0F, 0.0F, 0.0F}, {1.0F, 0.125F, 1.0F});
    this->powered = powered;
	mBlocks[blockId] = this;
	mOwnedBlocks.push_back(this);
}

const TextureUVCoordinateSet& RepeaterBlock::getTexture(signed char side, int data) {
    if(side == 1)
	return texture;
    return side_texture;
}

/*void RepeaterBlock::tick(TileSource* region, int x, int y, int z, Random* random) {
    int data = region->getData(x, y, z);
    bool shouldBePowered = isGettingPowered(region, x, y, z, data);
    if(powered && !shouldBePowered)
		region->setTileAndData(x, y, z, {93, data}, 3);
    else if(!powered) {
		region->setTileAndData(x, y, z, {94, data}, 3);
		if(!shouldBePowered) {
		    int delay = (data & 12) >> 2;
		    region->scheduleBlockUpdate(x, y, z, 94, delaySettings[delay] * 2);
		}
    }
}

int RepeaterTile::getResource(Random*, int, int) {
	return 356;
}

bool RepeaterTile::canSurvive(TileSource* region, int x, int y, int z) {
	return Tile::solid[region->getTile(x, y - 1, z).id] || region->isRedstonePlacementException(x, y - 1, z);
}

bool RepeaterTile::mayPlace(TileSource* region, int x, int y, int z) {
	return region->getTile(x, y, z).id == 0 && (Tile::solid[region->getTile(x, y - 1, z).id] || region->isRedstonePlacementException(x, y - 1, z));
}

int RepeaterTile::getSignal(TileSource* region, int x, int y, int z, int side) {
    return getDirectSignal(region, x, y, z, side);
}

int RepeaterTile::getDirectSignal(TileSource* region, int x, int y, int z, int side) {
    if(!powered)
		return 0;

    int rot = region->getData(x, y, z) & 3;
    if(rot == 0 && side == 3)
		return 15;
    if(rot == 1 && side == 4)
		return 15;
    if(rot == 2 && side == 2)
		return 15;
    return (rot == 3 && side == 5)? 15 : 0;
}

void RepeaterTile::neighborChanged(TileSource* region, int x, int y, int z, int changedX, int changedY, int changedZ) {
	if(!canSurvive(region, x, y, z)) {
		popResource(region, x, y, z, ItemInstance(Item::items[getResource(NULL, 0, 0)]));
		region->removeTile(x, y, z);
	}
    int data = region->getData(x, y, z);
    bool shouldBePowered = isGettingPowered(region, x, y, z, data);
    int delay = (data & 12) >> 2;
    if(powered && !shouldBePowered)
		region->scheduleBlockUpdate(x, y, z, id, delaySettings[delay] * 2);
    else if(!powered && shouldBePowered)
		region->scheduleBlockUpdate(x, y, z, id, delaySettings[delay] * 2);
}*/

bool RepeaterBlock::isGettingPowered(BlockSource& region, const BlockPos& pos, int data) {
    /*int rot = data & 3;

    switch(rot) {
    case 0:
		if(region->getTile(x, y, z + 1).id == 55 && region->getData(x, y, z + 1) > 0)
	    	return true;
		return region->getIndirectPowerLevelTo(x, y, z + 1, 3) > 0;
    case 2:
		if(region->getTile(x, y, z - 1).id == 55 && region->getData(x, y, z - 1) > 0)
	    	return true;
		return region->getIndirectPowerLevelTo(x, y, z - 1, 2) > 0;
    case 3:
		if(region->getTile(x + 1, y, z).id == 55 && region->getData(x + 1, y, z) > 0)
		    return true;
		return region->getIndirectPowerLevelTo(x + 1, y, z, 5) > 0;
    case 1:
		if(region->getTile(x - 1, y, z).id == 55 && region->getData(x - 1, y, z) > 0)
		    return true;
		return region->getIndirectPowerLevelTo(x - 1, y, z, 4) > 0;
    }*/
    return false;
}
/*
bool RepeaterTile::use(Player* player, int x, int y, int z) {
    int data = player->region.getData(x, y, z);
    int delay = (data & 12) >> 2;
    delay = delay + 1 << 2 & 12;
    player->region.setTileAndData(x, y, z, {id, delay | data & 3}, 3);
    return true;
}

bool RepeaterTile::isSignalSource() {
    return true;
}

int RepeaterTile::getPlacementDataValue(Mob* placer, int x, int y, int z, signed char side, float xx, float yy, float zz, int data) {
    return (((int) floor((placer->yaw * 4.0F / 360.0F) + 0.5F) & 3) + 2) % 4;
}

void RepeaterTile::onPlace(TileSource* region, int x, int y, int z) {
    if(isGettingPowered(region, x, y, z, region->getData(x, y, z)))
		region->scheduleBlockUpdate(x, y, z, id, 1);

    region->updateNeighborsAt({x + 1, y, z}, id);
    region->updateNeighborsAt({x - 1, y, z}, id);
    region->updateNeighborsAt({x, y, z + 1}, id);
    region->updateNeighborsAt({x, y, z - 1}, id);
    region->updateNeighborsAt({x, y - 1, z}, id);
    region->updateNeighborsAt({x, y + 1, z}, id);
}

void RepeaterTile::animateTick(TileSource* region, int x, int y, int z, Random*) {
	if(powered) {
		int data = region->getData(x, y, z);
		int rot = data & 3;
		float posX = (x + 0.5F) + (Mth::random() - 0.5F) * 0.2F;
		float posY = (y + 0.4F) + (Mth::random() - 0.5F) * 0.2F;
		float posZ = (z + 0.5F) + (Mth::random() - 0.5F) * 0.2F;
		float offsetX = 0.0F;
		float offsetZ = 0.0F;
		int setting = (data & 12) >> 2;

		switch(rot) {
		case 0:
			offsetZ = torchOffset[setting];
			break;
		case 1:
			offsetX = -torchOffset[setting];
			break;
		case 2:
			offsetZ = -torchOffset[setting];
			break;
		case 3:
			offsetX = torchOffset[setting];
		}

		region->getLevel()->addParticle(ParticleType::RedDust, {posX + offsetX, posY, posZ + offsetZ}, {0.0F, 0.0F, 0.0F}, 1);
	}
}*/
