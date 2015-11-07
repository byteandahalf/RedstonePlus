#pragma once
#include "global/blockutil.h"

struct BlockTickingQueue {
	void add(BlockSource&, const BlockPos&, BlockID, int);
};
