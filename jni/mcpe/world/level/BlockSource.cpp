#include "BlockSource.h"

void BlockSource::scheduleBlockUpdate(const BlockPos& pos, int blockId, int delay) {
	getTickQueue(pos)->add(*this, pos, blockId, delay);
}