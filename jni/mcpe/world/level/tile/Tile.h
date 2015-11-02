#pragma once

#include <string>
#include <vector>

class Material;
class TileEntity;
class TilePos;
class TileSource;
class Entity;
class Player;
class Mob;
class Random;
#include "../../item/ItemInstance.h"
class Vec3;
#include "../../../client/renderer/texture/TextureUVCoordinateSet.h"
#include "../../phys/AABB.h"
#include "../../../CommonTypes.h"
#include "mcperedstone/utils/CreativeTab.h"
#include "mcpe/world/level/tile/entity/TileEntityType.h"


class Tile {
public:
	class SoundType {
	public:
		float volume;
		float pitch;
		std::string breakSound;
		std::string stepSound;


		SoundType() {};
		SoundType(const std::string&, float, float);
	};


	bool replaceable; // 4
	AABB hitbox; // 8
	TextureUVCoordinateSet tex; // 36
	unsigned char id; // 68
	const Tile::SoundType* soundType; // 72
	bool canBuildOver; // 76
	int renderPass; // 80
	int renderType; // 84
	int tileType; // 88
	TileEntityType tileEntityType; // 92
	float thickness; // 96
	bool canFall; // 100
	bool canInstaTick; // 101
	float gravity; // 104
	Material* material; // 108
	float friction; // 112
	float destroyTime; // 116
	float explosionResistance; // 120
	CreativeTab creativeTab; // 124
	bool fancy; // 128
	unsigned int textureIsotropic; // 132
	std::string descriptionId; // 136


	static Tile* tiles[256];
	static bool solid[256];
	static float translucency[256];
	static uint_fast8_t lightBlock[256];
	static int lightEmission[256];
	static bool shouldTick[256];

	static const Tile::SoundType SOUND_NORMAL;
	static const Tile::SoundType SOUND_WOOD;
	static const Tile::SoundType SOUND_GRAVEL;
	static const Tile::SoundType SOUND_GRASS;
	static const Tile::SoundType SOUND_STONE;
	static const Tile::SoundType SOUND_METAL;
	static const Tile::SoundType SOUND_GLASS;
	static const Tile::SoundType SOUND_CLOTH;
	static const Tile::SoundType SOUND_SAND;
	static const Tile::SoundType SOUND_LADDER;
	static const Tile::SoundType SOUND_SILENT;


	Tile(int, Material const*);
	Tile(int, TextureUVCoordinateSet, Material const*);
	Tile(int, const std::string&, Material const*);

	virtual ~Tile();
	virtual void onFertilized(TileSource*, int, int, int);
	virtual const AABB& getVisualShape(TileSource*, int, int, int, AABB&, bool);
	virtual const AABB& getVisualShape(unsigned char, AABB&, bool);
	virtual const AABB& getCollisionShape(AABB&, TileSource&, int, int, int);
	virtual bool isObstructingChests(TileSource*, int, int, int);
	virtual bool shouldRenderFace(TileSource*, int, int, int, signed char, const AABB&) const;
	virtual const TextureUVCoordinateSet& getTexture(signed char);
	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual const TextureUVCoordinateSet& getTexture(TileSource*, int, int, int, signed char);
	virtual void getTessellatedUVs();
	virtual void getCarriedTexture(signed char, int);
	virtual AABB* getAABB(TileSource*, int, int, int, AABB&, int, bool, int);
	virtual void addAABBs(TileSource*, int, int, int, const AABB*, std::vector<AABB, std::allocator<AABB>>&);
	virtual bool addCollisionShapes(TileSource&, int, int, int, const AABB*, std::vector<AABB, std::allocator<AABB>>&);
	virtual int getRenderLayer(TileSource*, const TilePos&) const;
	virtual float getThickness() const;
	virtual bool isCropTile() const;
	virtual bool isContainerTile() const;
	virtual bool isCraftingTile() const;
	virtual bool isInteractiveTile() const;
	virtual bool isPathfindable(Entity*, const TilePos&, int, int, int);
	virtual bool mayPick();
	virtual bool mayPick(TileSource*, int, bool);
	virtual bool mayPlace(TileSource*, int, int, int, signed char);
	virtual bool mayPlace(TileSource*, int, int, int);
	virtual void tryToPlace(TileSource*, const TilePos&, unsigned char);
	virtual void tick(TileSource*, int, int, int, Random*);
	virtual void animateTick(TileSource*, int, int, int, Random*);
	virtual void destroy(TileSource*, int, int, int, int, Entity*);
	virtual void playerWillDestroy(Player*, int, int, int, int);
	virtual void neighborChanged(TileSource*, int, int, int, int, int, int);
	virtual void onPlace(TileSource*, int, int, int);
	virtual void onRemove(TileSource*, int, int, int);
	virtual void getSecondPart(TileSource&, const TilePos&, TilePos&);
	virtual void onGraphicsModeChanged(bool, bool);
	virtual int getResource(Random*, int, int);
	virtual int getResourceCount(Random*, int, int);
	virtual void getDestroyProgress(Player*);
	virtual void spawnResources(TileSource*, int, int, int, int, float, int);
	virtual void spawnBurnResources(TileSource*, float, float, float);
	virtual float getExplosionResistance(Entity*);
	virtual void clip(TileSource*, int, int, int, const Vec3&, const Vec3&, bool, int);
	virtual void wasExploded(TileSource*, int, int, int, Entity*);
	virtual bool use(Player*, int, int, int);
	virtual void stepOn(Entity*, int, int, int);
	virtual void fallOn(TileSource*, int, int, int, Entity*, float);
	virtual int getPlacementDataValue(Mob*, int, int, int, signed char, float, float, float, int);
	virtual void prepareRender(TileSource*, int, int, int);
	virtual void attack(Player*, int, int, int);
	virtual void handleEntityInside(TileSource*, int, int, int, Entity*, Vec3&);
	virtual int getColor(int);
	virtual int getColor(TileSource*, int, int, int);
	virtual bool isSeasonTinted(TileSource*, const TilePos&) const;
	virtual bool isSignalSource();
	virtual bool getSignal(TileSource*, int, int, int);
	virtual int getSignal(TileSource*, int, int, int, int);
	virtual int getDirectSignal(TileSource*, int, int, int, int);
	virtual bool entityInside(TileSource*, int, int, int, Entity*);
	virtual void playerDestroy(Player*, int, int, int, int);
	virtual bool canSurvive(TileSource*, int, int, int);
	virtual int getExperienceDrop(Random*) const;
	virtual bool canBeBuiltOver(TileSource&, int, int, int) const;
	virtual Tile* setNameId(const std::string&);
	virtual std::string getName(const ItemInstance*) const;
	virtual void triggerEvent(TileSource*, int, int, int, int, int);
	virtual TextureUVCoordinateSet getTextureNum(int);
	virtual void getMobToSpawn(TileSource&, const TilePos&) const;
	virtual int getIconYOffset() const;
	virtual bool shouldStopFalling(Entity*);
	virtual float calcGroundFriction(Mob*, const TilePos&) const;
	virtual bool canHaveExtraData() const;
	virtual void setVisualShape(float, float, float, float, float, float);
	virtual Tile* setSoundType(const Tile::SoundType&);
	virtual Tile* setLightBlock(Brightness);
	virtual Tile* setLightEmission(float);
	virtual Tile* setExplodeable(float);
	virtual Tile* setDestroyTime(float);
	virtual Tile* setFriction(float);
	virtual void setTicking(bool);
	virtual void getSpawnResourcesAuxValue(int);
	virtual Tile* init();
	virtual bool _canBeSilkTouched() const;

	void addAABB(const AABB&, const AABB*, std::vector<AABB, std::allocator<AABB>>&);
	void popResource(TileSource*, int, int, int, const ItemInstance&);
	TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int);
	Tile* setCategory(int);
	static void initTiles();


	static Tile* rock; // 1
	static Tile* grass; // 2
	static Tile* dirt; // 3
	static Tile* stoneBrick; // 4
	static Tile* wood; // 5
	static Tile* sapling; // 6
	static Tile* unbreakable; // 7
	static Tile* water; // 8
	static Tile* calmWater; // 9
	static Tile* lava; // 10
	static Tile* calmLava; // 11
	static Tile* sand; // 12
	static Tile* gravel; // 13
	static Tile* goldOre; // 14
	static Tile* ironOre; // 15
	static Tile* coalOre; // 16
	static Tile* log; // 17
	static Tile* leaves; // 18
	static Tile* sponge; // 19
	static Tile* glass; // 20
	static Tile* lapisOre; // 21
	static Tile* lapisBlock; // 22
	static Tile* dispenser; // 23
	static Tile* sandStone; // 24
	static Tile* musicBlock; // 25
	static Tile* bed; // 26
	static Tile* goldenRail; // 27
	static Tile* redstoneRail; // 28
	static Tile* pistonSticky; // 29
	static Tile* web; // 30
	static Tile* tallgrass; // 31
	static Tile* deadBush; // 32
	static Tile* pistonNormal; // 33
	static Tile* pistonArm; // 34
	static Tile* cloth; // 35
	static Tile* pistonMoving; // 36
	static Tile* yellowFlower; // 37
	static Tile* redFlower; // 38
	static Tile* brownMushroom; // 39
	static Tile* redMushroom; // 40
	static Tile* goldBlock; // 41
	static Tile* ironBlock; // 42
	static Tile* stoneSlab; // 43
	static Tile* stoneSlabHalf; // 44
	static Tile* redBrick; // 45
	static Tile* tnt; // 46
	static Tile* bookshelf; // 47
	static Tile* mossStone; // 48
	static Tile* obsidian; // 49
	static Tile* torch; // 50
	static Tile* fire; // 51
	static Tile* mobSpawner; // 52
	static Tile* stairs_wood; // 53
	static Tile* chest; // 54
	static Tile* redStoneDust; // 55
	static Tile* diamondOre; // 56
	static Tile* diamondBlock; // 57
	static Tile* workBench; // 58
	static Tile* crops; // 59
	static Tile* farmland; // 60
	static Tile* furnace; // 61
	static Tile* furnace_lit; // 62
	static Tile* sign; // 63
	static Tile* door_wood; // 64
	static Tile* ladder; // 65
	static Tile* rail; // 66
	static Tile* stairs_stone; // 67
	static Tile* wallSign; // 68
	static Tile* lever; // 69
	static Tile* pressurePlate_stone; // 70
	static Tile* door_iron; // 71
	static Tile* pressurePlate_wood; // 72
	static Tile* redStoneOre; // 73
	static Tile* redStoneOre_lit; // 74
	static Tile* notGate_off; // 75
	static Tile* notGate_on; // 76
	static Tile* button; // 77
	static Tile* topSnow; // 78
	static Tile* ice; // 79
	static Tile* snow; // 80
	static Tile* cactus; // 81
	static Tile* clay; // 82
	static Tile* reeds; // 83
	static Tile* recordPlayer; // 84
	static Tile* fence; // 85
	static Tile* pumpkin; // 86
	static Tile* netherrack; // 87
	static Tile* soulSand; // 88
	static Tile* lightGem; // 89
	static Tile* portal; // 90
	static Tile* litPumpkin; // 91
	static Tile* cake; // 92
	static Tile* diode_off; // 93
	static Tile* diode_on; // 94
	static Tile* invisible_bedrock; // 95
	static Tile* trapdoor; // 96
	static Tile* monsterStoneEgg; // 97
	static Tile* stoneBrickSmooth; // 98
	static Tile* brownMushroomBlock; // 99
	static Tile* redMushroomBlock; // 100
	static Tile* ironFence; // 101
	static Tile* thinGlass; // 102
	static Tile* melon; // 103
	static Tile* pumpkinStem; // 104
	static Tile* melonStem; // 105
	static Tile* vine; // 106
	static Tile* fenceGateOak; // 107
	static Tile* stairs_brick; // 108
	static Tile* stairs_stoneBrickSmooth; // 109
	static Tile* mycelium; // 110
	static Tile* waterlily; // 111
	static Tile* netherBrick; // 112
	static Tile* netherFence; // 113
	static Tile* stairs_netherBricks; // 114
	static Tile* enchantingTable; // 116
	static Tile* brewing_stand; // 117
	static Tile* endPortalFrame; // 120
	static Tile* endStone; // 121
	static Tile* offlamp; // 123
	static Tile* onlamp; // 124
	static Tile* activatorRail; // 126
	static Tile* cocoa; // 127
	static Tile* stairs_sandStone; // 128
	static Tile* emeraldOre; // 129
	static Tile* emeraldBlock; // 133
	static Tile* woodStairsDark; // 134
	static Tile* woodStairsBirch; // 135
	static Tile* woodStairsJungle; // 136
	static Tile* cobbleWall; // 139
	static Tile* flowerPot; // 140
	static Tile* carrots; // 141
	static Tile* potatoes; // 142
	static Tile* buttonWood; // 143
	static Tile* skull; // 144
	static Tile* anvil; // 145
	static Tile* pressurePlate_gold; // 147
	static Tile* pressurePlate_iron; // 148
	static Tile* redstoneBlock; // 152
	static Tile* quartzOre; // 153
	static Tile* quartzBlock; // 155
	static Tile* stairs_quartz; // 156
	static Tile* woodSlab; // 157
	static Tile* woodSlabHalf; // 158
	static Tile* stainedClay; // 159
	static Tile* leaves2; // 161
	static Tile* log2; // 162
	static Tile* woodStairsAcacia; // 163
	static Tile* woodStairsBigOak; // 164
	static Tile* hayBlock; // 170
	static Tile* woolCarpet; // 171
	static Tile* hardenedClay; // 172
	static Tile* coalBlock; // 173
	static Tile* packedIce; // 174
	static Tile* doublePlant; // 175
	static Tile* fenceGateSpruce; // 183
	static Tile* fenceGateBirch; // 184
	static Tile* fenceGateJungle; // 185
	static Tile* fenceGateBigOak; // 186
	static Tile* fenceGateAcacia; // 187
	static Tile* grassPathBlock; // 198
	static Tile* podzol; // 243
	static Tile* beetroot; // 244
	static Tile* stonecutterBench; // 245
	static Tile* glowingObsidian; // 246
	static Tile* netherReactor; // 247
	static Tile* info_updateGame1; // 248
	static Tile* info_updateGame2; // 249
	static Tile* info_reserved6; // 255
};
