#pragma once

#include <string>
#include <functional>

class Tessellator;
class TilePos;
class Tile;
class TileSource;
class Vec3;
#include "../texture/TextureUVCoordinateSet.h"
#include "../../../world/phys/AABB.h"
#include "../../../CommonTypes.h"

class RedstoneWireTile;
class NotGateTile;
class LeverTile;
class RepeaterTile;
class PistonBaseTile;
class PistonArmTile;

class TileTessellator {
public:
	bool forceOpaque; // 0
	bool otherb; // 1
	TileSource* region; // 4
	TextureUVCoordinateSet forcedUV; // 8
	bool useForcedUV; // 40
	char filler[88]; // 44
	int rotBottom; // 132
	int rotTop; // 136
	int rotEast; // 140
	int rotWest; // 144
	int rotNorth; // 148
	int rotSouth; // 152
	char filler1[512]; // 156
	Tessellator* tessellator; // 668
	AABB bounds; // 672

	bool tessellateInWorld(Tile*, const TilePos&, unsigned char, bool);
	bool tessellateBlockInWorld(Tile*, const TilePos&);
	void renderFaceUp(Tile*, const Vec3&, const TextureUVCoordinateSet&);
	void tessellateTorch(Tile*, float, float, float, float, float);
	void tex1(unsigned int);
	DataID getData(const TilePos&) const;
	unsigned int getLightColor(const TilePos&);

	bool tessellateRedstoneWireInWorld(RedstoneWireTile*, const TilePos&);
	bool tessellateLitNotGateInWorld(NotGateTile*, const TilePos&);
	void tessellateAngledNotGate(Tile*, double, double, double, double, double);
	bool tessellateLeverInWorld(LeverTile*, const TilePos&);
	bool tessellateRepeaterInWorld(RepeaterTile*, const TilePos&);
	//bool tessellatePistonBaseAllFaces(PistonBaseTile*, const TilePos&, bool);
	bool tessellatePistonBaseInWorld(PistonBaseTile*, const TilePos&, bool);
	//bool tessellatePistonArmAllFaces(PistonArmTile*, const TilePos&, bool);
	bool tessellatePistonArmInWorld(PistonArmTile*, const TilePos&, bool);
	void tessellatePistonRodUD(PistonArmTile*, float, float, float, float, float, float, float, float);
	void tessellatePistonRodSN(PistonArmTile*, float, float, float, float, float, float, float, float);
	void tessellatePistonRodEW(PistonArmTile*, float, float, float, float, float, float, float, float);
};
