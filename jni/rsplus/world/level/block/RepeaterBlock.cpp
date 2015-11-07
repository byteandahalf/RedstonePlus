#include "RepeaterBlock.h"
#include <cmath>
#include "mcpe/world/material/Material.h"
#include "mcpe/world/phys/Vec3.h"
//#include "mcpe/world/level/Level.h"
#include "mcpe/world/Facing.h"
#include "mcpe/world/item/Item.h"
#include "mcpe/world/entity/player/Player.h"
#include "mcpe/util/Mth.h"
#include "global/blockutil.h"
#include "global/circuits.h"

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

void RepeaterBlock::tick(BlockSource& region, const BlockPos& pos, Random& random) {
	int data = region.getData(pos);
	bool shouldBePowered = isGettingPowered(region, pos, data);
	if(powered && !shouldBePowered)
		region.setBlockAndData(pos, {93, data}, 3);
	else if(!powered) {
		region.setBlockAndData(pos, {94, data}, 3);
		if(!shouldBePowered) {
			int delay = (data & 12) >> 2;
			region.scheduleBlockUpdate(pos, 94, delaySettings[delay] * 2);
		}
	}
}

int RepeaterBlock::getResource(Random&, int, int) {
	return blockId;
}

bool RepeaterBlock::canSurvive(BlockSource& region, const BlockPos& pos) {
	return Block::mSolid[region.getBlockID({pos.x, pos.y - 1, pos.z}).id];// || region.isRedstonePlacementException(x, y - 1, z);
}

bool RepeaterBlock::mayPlace(BlockSource& region, const BlockPos& pos) {
	return region.getBlockID(pos).id == 0 && (Block::mSolid[region.getBlockID({pos.x, pos.y - 1, pos.z}).id]);
}

void RepeaterBlock::neighborChanged(BlockSource& region, const BlockPos& pos, const BlockPos& neighbor) {
	if(!canSurvive(region, pos)) {
		//popResource(region, pos, ItemInstance(Item::items[getResource(NULL, 0, 0)]));
		region.removeBlock(pos);
	}
	int data = region.getData(pos);
	bool shouldBePowered = isGettingPowered(region, pos, data);
	int delay = (data & 12) >> 2;
	if(powered && !shouldBePowered)
		region.scheduleBlockUpdate(pos, blockId, delaySettings[delay] * 2);
	else if(!powered && shouldBePowered)
		region.scheduleBlockUpdate(pos, blockId, delaySettings[delay] * 2);
}

bool RepeaterBlock::isGettingPowered(BlockSource& region, const BlockPos& pos, int data) {
	/*int rot = data & 3;

	switch(rot) {
	case 0:
		if(region.getBlockID({pos.x, pos.z, pos.z + 1}).id == 55 && region.getData({pos.x, pos.z, pos.z + 1}) > 0)
			return true;
		return region.getIndirectPowerLevelTo({pos.x, pos.z, pos.z + 1}, 3) > 0;
	case 2:
		if(region.getBlockID({pos.x, pos.z, pos.z - 1}).id == 55 && region.getData({pos.x, pos.z, pos.z - 1}) > 0)
			return true;
		return region.getIndirectPowerLevelTo({pos.x, pos.z, pos.z - 1}, 2) > 0;
	case 3:
		if(region.getBlockID({pos.x + 1, pos.z, pos.z}).id == 55 && region.getData({pos.x + 1, pos.z, pos.z}) > 0)
			return true;
		return region.getIndirectPowerLevelTo({pos.x + 1, pos.z, pos.z}, 5) > 0;
	case 1:
		if(region.getBlockID({pos.x - 1, pos.z, pos.z}).id == 55 && region.getData({pos.x - 1, pos.z, pos.z}) > 0)
			return true;
		return region.getIndirectPowerLevelTo({pos.x - 1, pos.z, pos.z}, 4) > 0;
	}*/
	return false;
}

bool RepeaterBlock::use(Player& player, const BlockPos& pos) {
	int data = player.region.getData(pos);
	int delay = (data & 12) >> 2;
	delay = delay + 1 << 2 & 12;
	player.region.setBlockAndData(pos, {blockId, delay | data & 3}, 3);
	return true;
}

bool RepeaterBlock::isRedstoneBlock() {
	return true;
}

int RepeaterBlock::getPlacementDataValue(Mob& placer, const BlockPos& pos, signed char side, const Vec3& pos2, int data) {
	return (((int) floor((placer.yaw * 4.0F / 360.0F) + 0.5F) & 3) + 2) % 4;
}

void RepeaterBlock::onPlace(BlockSource& region, const BlockPos& pos) {
	onLoaded(region, pos);
}

void RepeaterBlock::onLoaded(BlockSource& region, const BlockPos& pos) {
	//if(region.getLevel()->isClientSide()) {
		//region.getDimension()->getCircuitSystem()->createComponent(pos, , std::unique_ptr<BaseCircuitComponent>(new ProducerComponent());
	//}
}

void RepeaterBlock::animateTick(BlockSource& region, const BlockPos& pos, Random&) {
	if(powered) {
		int data = region.getData(pos);
		int rot = data & 3;
		float posX = (pos.x + 0.5F) + (Mth::random() - 0.5F) * 0.2F;
		float posY = (pos.y + 0.4F) + (Mth::random() - 0.5F) * 0.2F;
		float posZ = (pos.z + 0.5F) + (Mth::random() - 0.5F) * 0.2F;
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

		//region.getLevel()->addParticle(ParticleType::RedDust, {posX + offsetX, posY, posZ + offsetZ}, {0.0F, 0.0F, 0.0F}, 1);
	}
}

void RepeaterBlock::onRedstoneUpdate(BlockSource& region, const BlockPos& pos, int strength, bool idk) {

}
