#pragma once

#include "Item.h"

class TileItem : public Item {
public:
	char data[12];

	TileItem(int);
};
