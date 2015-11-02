#pragma once
#include <string>
#include <vector>
class Tile;
class ItemInstance;
#include "../../client/renderer/texture/TextureUVCoordinateSet.h"
class Entity;
class Player;
class Mob;
class Level;
class Tile;
#include "mcperedstone/utils/CreativeTab.h"
namespace RakNet {
class BitStream;
};

class Item {
public:
	int maxStackSize; // 4
	std::string atlas; // 8
	int frameCount; // 12
	int idk; // 16
	std::string name; // 20
	const short id; // 24
	short maxDamage; // 26
	TextureUVCoordinateSet icon; // 28
	CreativeTab creativeTab; // 60
	bool renderAsSword; // 64
	bool _isStackedByData; // 65
	Item* craftingRemainingItem; // 68

	Item(int);

	virtual ~Item();
	virtual int getMaxStackSize(const ItemInstance*);
	virtual void setMaxStackSize(unsigned char);
	virtual bool canBeDepleted();
	virtual TextureUVCoordinateSet getIcon(int, int, bool) const;
	virtual int getIconYOffset() const;
	virtual void setIcon(std::string const&, int);
	virtual void setIcon(TextureUVCoordinateSet);
	virtual bool isMirroredArt() const;
	virtual void use(ItemInstance&, Player&);
	virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
	virtual int getMaxUseDuration() const;
	virtual void useTimeDepleted(ItemInstance*, Level*, Player*);
	virtual int getUseAnimation() const;
	virtual void releaseUsing(ItemInstance*, Player*, int);
	virtual float getDestroySpeed(ItemInstance*, Tile*);
	virtual bool canDestroySpecial(const Tile*) const;
	virtual void* getLevelDataForAuxValue(int) const;
	virtual bool isStackedByData() const;
	virtual int getMaxDamage();
	virtual int getAttackDamage(Entity*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual void interactEnemy(ItemInstance*, Mob*, Player*);
	virtual void mineBlock(ItemInstance*, int, int, int, int, Mob*);
	virtual void handEquipped();
	virtual bool isHandEquipped() const;
	virtual bool isFood() const;
	virtual bool isSeed() const;
	virtual bool isArmor() const;
	virtual bool isDye() const;
	virtual bool isFoil(const ItemInstance*) const;
	virtual bool isThrowable() const;
	virtual bool canDestroyInCreative() const;
	virtual bool isLiquidClipItem(int) const;
	virtual bool requiresInteract() const;
	virtual std::string getInteractText() const;
	virtual std::string getName(const ItemInstance*) const;
	virtual std::string getEffectName(const ItemInstance&) const;
	virtual void appendFormattedHovertext(std::string&, const ItemInstance&) const;
	virtual void setNameID(std::string const&);
	virtual void readUserData(ItemInstance*, RakNet::BitStream*) const;
	virtual void writeUserData(const ItemInstance*, RakNet::BitStream*, bool) const;
	virtual bool isEmissive(int) const;
	virtual int getAnimationFrameFor(Mob&) const;
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&);
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;

	static void initItems();
	static void initCreativeItems();
	static void addCreativeItem(Tile*, short);
	static void addCreativeItem(Item*, short);
	static std::vector<ItemInstance> creativeList;

	static Item* items[512];

	static Item* shovel_iron;
	static Item* pickAxe_iron;
	static Item* hatchet_iron;
	static Item* flintAndSteel;
	static Item* apple;
	static Item* bow;
	static Item* arrow;
	static Item* coal;
	static Item* diamond;
	static Item* ironIngot;
	static Item* goldIngot;
	static Item* sword_iron;
	static Item* sword_wood;
	static Item* shovel_wood;
	static Item* pickAxe_wood;
	static Item* hatchet_wood;
	static Item* sword_stone;
	static Item* shovel_stone;
	static Item* pickAxe_stone;
	static Item* hatchet_stone;
	static Item* sword_diamond;
	static Item* shovel_diamond;
	static Item* pickAxe_diamond;
	static Item* hatchet_diamond;
	static Item* stick;
	static Item* bowl;
	static Item* mushroomStew;
	static Item* sword_gold;
	static Item* shovel_gold;
	static Item* pickAxe_gold;
	static Item* hatchet_gold;
	static Item* string;
	static Item* feather;
	static Item* sulphur;
	static Item* hoe_wood;
	static Item* hoe_stone;
	static Item* hoe_iron;
	static Item* hoe_diamond;
	static Item* hoe_gold;
	static Item* seeds_wheat;
	static Item* wheat;
	static Item* bread;
	static Item* helmet_cloth;
	static Item* chestplate_cloth;
	static Item* leggings_cloth;
	static Item* boots_cloth;
	static Item* helmet_chain;
	static Item* chestplate_chain;
	static Item* leggings_chain;
	static Item* boots_chain;
	static Item* helmet_iron;
	static Item* chestplate_iron;
	static Item* leggings_iron;
	static Item* boots_iron;
	static Item* helmet_diamond;
	static Item* chestplate_diamond;
	static Item* leggings_diamond;
	static Item* boots_diamond;
	static Item* helmet_gold;
	static Item* chestplate_gold;
	static Item* leggings_gold;
	static Item* boots_gold;
	static Item* flint;
	static Item* porkChop_raw;
	static Item* porkChop_cooked;
	static Item* painting;
	static Item* apple_gold;
	static Item* sign;
	static Item* door_wood;
	static Item* bucket;
	static Item* minecart;
	static Item* saddle;
	static Item* door_iron;
	static Item* redStone;
	static Item* snowBall;
	static Item* boat;
	static Item* leather;
	static Item* brick;
	static Item* clay;
	static Item* reeds;
	static Item* paper;
	static Item* book;
	static Item* slimeBall;
	static Item* egg;
	static Item* compass;
	static Item* fishingRod;
	static Item* clock;
	static Item* yellowDust;
	static Item* fish_raw;
	static Item* fish_cooked;
	static Item* melon;
	static Item* seeds_pumpkin;
	static Item* seeds_melon;
	static Item* mobPlacer;
	static Item* dye_powder;
	static Item* bone;
	static Item* sugar;
	static Item* cake;
	static Item* bed;
	static Item* cookie;
	static Item* pumpkinPie;
	static Item* potato;
	static Item* potatoBaked;
	static Item* carrot;
	static Item* beetroot;
	static Item* seeds_beetroot;
	static Item* beetrootSoup;
	static Item* shears;
	static Item* beef_raw;
	static Item* beef_cooked;
	static Item* chicken_raw;
	static Item* chicken_cooked;
	static Item* netherbrick;
	static Item* netherQuartz;
	static Item* camera;
	static Item* emerald;
	static Item* blazePowder;
	static Item* blazeRod;
	static Item* brewing_stand;
	static Item* enchanted_book;
	static Item* experiencePotionItem;
	static Item* fermented_spider_eye;
	static Item* flowerPot;
	static Item* ghast_tear;
	static Item* glass_bottle;
	static Item* gold_nugget;
	static Item* golden_carrot;
	static Item* magma_cream;
	static Item* nether_wart;
	static Item* poisonous_potato;
	static Item* potion;
	static Item* rabbit_foot;
	static Item* rotten_flesh;
	static Item* skull;
	static Item* speckled_melon;
	static Item* spider_eye;
	static Item* splash_potion;
	static Item* repeater;
};
