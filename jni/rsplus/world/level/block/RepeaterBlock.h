#pragma once
#include "mcpe/world/level/block/Block.h"

class RepeaterBlock : public Block {
public:
	bool powered;
	TextureUVCoordinateSet side_texture;

	RepeaterBlock(int, const std::string&, bool);

	static float torchOffset[4];

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
/*	virtual void tick(BlockSource&, const BlockPos&, Random&);
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&);
	virtual bool isRedstoneBlock();
	virtual int getPlacementDataValue(Mob&, const BlockPos&, signed char, const Vec3&, int);
	virtual void onPlace(BlockSource&, const BlockPos&);
	virtual void onLoaded(BlockSource&, const BlockPos&);
	virtual bool canSurvive(BlockSource&, const BlockPos&);
	virtual bool mayPlace(BlockSource&, const BlockPos&);
	virtual bool use(Player&, const BlockPos&);
	virtual int getResource(Random&, int, int);
	virtual void animateTick(BlockSource&, const BlockPos&, Random&);
	virtual void onRedstoneUpdate(BlockSource&, const BlockPos&, int, bool);*/

private:
	bool isGettingPowered(BlockSource&, const BlockPos&, int);
	static int delaySettings[4];
};
