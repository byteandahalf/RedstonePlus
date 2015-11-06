#pragma once
#include <vector>

enum class MaterialType : int {
	DIRT = 1,
	WOOD,
	STONE,
	IRON,
	WOOL,
	DECORATION = 8,
	PLANT,
	SAND = 14,
	TORCH,
	PORTAL = 25,
	CIRCUIT = 28,
	LAMP = 30
};

class Material {
	MaterialType type; // 0
	bool flammable; // 4
	bool neverBuildable; // 5
	bool alwaysBreakable; // 6
	bool replaceable; // 7
	bool liquid; // 8
	float translucency; // 12
	bool blocksMotion; // 16
	bool solid; // 17
	bool superHot; // 18
	
public:
	typedef int Settings;
	
	static std::vector<Material> mMaterials;
	
	Material(MaterialType, Material::Settings, float);
	
	bool isType(MaterialType);
	bool isFlammable();
	bool isNeverBuildable();
	bool isAlwaysDestroyable();
	bool isReplaceable();
	bool isLiquid();
	float getTranslucency();
	bool getBlocksMotion();
	bool isSolid();
	bool isSuperHot();
	
	static void initMaterials();
};
