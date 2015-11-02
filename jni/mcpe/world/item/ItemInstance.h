#pragma once

class Item;
class Tile;
class CompoundTag;

class ItemInstance {
public:
	short count;
	short damage;
	CompoundTag* userData;
	Item* item;
	Tile* tile;
	char filler[4];

	void _setItem(int);
	ItemInstance(int, int, int);
	ItemInstance(const ItemInstance&);
	ItemInstance(const Item*);
	ItemInstance(const Item*, int, int);
	ItemInstance(const Tile*);
	ItemInstance(const Tile*, int, int);
	ItemInstance();
};
