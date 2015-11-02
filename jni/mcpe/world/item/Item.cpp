#pragma once
#include "Item.h"
#include "ItemInstance.h"

void Item::addCreativeItem(Item* item, short data) {
	ItemInstance add(creativeList[0]);
	add.item = item;
	add.damage = data;
	creativeList.push_back(add);
}
