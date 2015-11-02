#pragma once
#include <vector>
#include <string>
#include "mcpe/world/item/ItemInstance.h"
class Item;
class Tile;

class Recipes {
public:
	struct Type {
		Item* item;
		Tile* tile;
		ItemInstance inst;
		char letter;
	};

	static Recipes* getInstance();
	static Recipes* instance;
    
	void init();
	void addShapedRecipe(const ItemInstance&, const std::vector<std::string>&, const std::vector<Recipes::Type>&);
};
