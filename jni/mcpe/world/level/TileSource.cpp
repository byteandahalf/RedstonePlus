#include "TileSource.h"
#include "tile/Tile.h"
#include "../Facing.h"
#include <cmath>


void TileSource::scheduleBlockUpdate(int x, int y, int z, int id, int delay) {
	getTickQueue({x, y, z})->add(this, {x, y, z}, id, delay);
}

bool TileSource::isBlockIndirectlyGettingPowered(int x, int y, int z) {
	if(getIndirectPowerLevelTo(x, y - 1, z, 0) > 0) return true;
	if(getIndirectPowerLevelTo(x, y + 1, z, 1) > 0) return true;
	if(getIndirectPowerLevelTo(x, y, z - 1, 2) > 0) return true;
	if(getIndirectPowerLevelTo(x, y, z + 1, 3) > 0) return true;
	if(getIndirectPowerLevelTo(x - 1, y, z, 4) > 0) return true;
	return getIndirectPowerLevelTo(x + 1, y, z, 5) > 0;
}

int TileSource::getIndirectPowerLevelTo(int x, int y, int z, int side) {
	int id = getTile(x, y, z).id;
	if(id == 0) return 0;
	if(Tile::solid[id] && id != Tile::redstoneBlock->id) return getBlockPowerInput(x, y, z);
	else return Tile::tiles[id]->getDirectSignal(this, x, y, z, side);
}

int TileSource::getStrongestIndirectPower(int x, int y, int z) {
	int var4 = 0;

	for (int var5 = 0; var5 < 6; ++var5) {
		int var6 = getIndirectPowerLevelTo(x + Facing::STEP_X[var5], y + Facing::STEP_Y[var5], z + Facing::STEP_Z[var5], var5);

		if(var6 >= 15)
			return 15;
		if(var6 > var4)
			var4 = var6;
	}
	return var4;
}

int TileSource::isBlockProvidingPowerTo(int x, int y, int z, int side) {
	int id = getTile(x, y, z).id;
	if(id == 0) return 0;
	else return Tile::tiles[id]->getSignal(this, x, y, z, side);
}

bool TileSource::getIndirectPowerOutput(int x, int y, int z, int side) {
	return getIndirectPowerLevelTo(x, y, z, side) > 0;
}

bool TileSource::isBlockGettingPowered(int x, int y, int z) {
	if(isBlockProvidingPowerTo(x, y - 1, z, 0)) return true;
	if(isBlockProvidingPowerTo(x, y + 1, z, 1)) return true;
	if(isBlockProvidingPowerTo(x, y, z - 1, 2)) return true;
	if(isBlockProvidingPowerTo(x, y, z + 1, 3)) return true;
	if(isBlockProvidingPowerTo(x - 1, y, z, 4)) return true;
	return isBlockProvidingPowerTo(x + 1, y, z, 5);
}

int TileSource::getBlockPowerInput(int x, int y, int z) {
	int var4 = 0;
	int var5 = std::max(var4, isBlockProvidingPowerTo(x, y - 1, z, 0));

	if(var5 >= 15)
		return var5;
	else {
		var5 = std::max(var5, isBlockProvidingPowerTo(x, y + 1, z, 1));

		if(var5 >= 15)
			return var5;
		else {
			var5 = std::max(var5, isBlockProvidingPowerTo(x, y, z - 1, 2));

			if(var5 >= 15)
				return var5;
			else {
				var5 = std::max(var5, isBlockProvidingPowerTo(x, y, z + 1, 3));

				if(var5 >= 15)
					return var5;
				else {
					var5 = std::max(var5, isBlockProvidingPowerTo(x - 1, y, z, 4));

					if(var5 >= 15)
						return var5;
					else {
						var5 = std::max(var5, isBlockProvidingPowerTo(x + 1, y, z, 5));
						return var5 >= 15 ? var5 : var5;
					}
				}
			}
		}
	}
}

bool TileSource::isRedstonePlacementException(int x, int y, int z) {
	int id = getTile(x, y, z).id;
	return (id == 44 && (getData(x, y, z) & 8) > 0) || (id == 158 && (getData(x, y, z) & 8) > 0) || id == 89;
}
