#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <substrate.h>
#include <string>

#include "mcpe/world/material/Material.h"
#include "mcpe/world/item/BlockItem.h"

#include "rsplus/world/level/block/RepeaterBlock.h"

void initBlockItems() {
	Item::mItems[93] = new BlockItem("diode", 93 - 0x100);
}

void (*_Block$initBlocks)();
void Block$initBlocks() {
	_Block$initBlocks();
	
	RepeaterBlock* repeater_off = new RepeaterBlock(93, "repeater_off", false);
	initBlockItems();
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems() {
	_Item$initCreativeItems();
	
	Item::addCreativeItem(Block::mBlocks[93], 0);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	
	return JNI_VERSION_1_2;
}
