#pragma once

#include <string>
#include <memory>
#include <vector>

class TileSource;
class Level;
class Entity;
class Material;
class Player;
class EntityPos;
class Vec2;
class CompoundTag;
class EntityLink;
class EntityDamageSource;
class ItemInstance;
class EntityEvent;
class DimensionId;
class ChangeDimensionPacket;
class AABB;
#include "../phys/Vec3.h"


class Entity {
public:
	//void** vtable; // 0
	char synchedData[20]; // 4
	float x; // 24
	float y; // 28
	float z; // 32
	Vec3 chunkPos; // 36
	TileSource& region; // 48
	int added; // 52
	int idk; // 56
	Level* level; // 60
	float oldX; // 64
	float oldY; // 68
	float oldZ; // 72
	float velX; // 76
	float velY; // 80
	float velZ; // 84
	float yaw; // 88
	float pitch; // 92
	char filler[92]; // 96
	float heightOffset; // 188

	virtual ~Entity();
	virtual void _postInit();
	virtual void reset();
	virtual int getOwnerEntityType();
	virtual void remove();
	virtual void setPos(float, float, float);
	virtual void setPos(const Vec3&);
	virtual Vec3& getPos() const;
	virtual Vec3& getPosOld() const;
	virtual Vec3& getPosExtrapolated(float) const;
	virtual Vec3& getVelocity() const;
	virtual void setRot(float, float);
	virtual void move(float, float, float);
	virtual void checkTileCollisions();
	virtual void moveTo(float, float, float, float, float);
	virtual void moveRelative(float, float, float);
	virtual void lerpTo(const Vec3&, const Vec2&, int);
	virtual void lerpMotion(float, float, float);
	virtual void turn(float, float);
	virtual void interpolateTurn(float, float);
	virtual void* getAddPacket();
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void* positionRider(Entity&) const;
	virtual float getRidingHeight();
	virtual float getRideHeight() const;
	virtual int getRideUseAnimation() const;
	virtual void startRiding(Entity&);
	virtual void addRider(Entity&);
	virtual void removeRider(Entity&);
	virtual bool intersects(float, float, float, float, float, float);
	virtual bool isFree(float, float, float, float);
	virtual bool isFree(float, float, float);
	virtual bool isInWall();
	virtual bool isInvisible();
	virtual bool canShowNameTag();
	virtual void setNameTagVisible(bool);
	virtual void* getNameTag() const;
	virtual void setNameTag(const std::string&);
	virtual bool isInWater() const;
	virtual bool isInWaterOrRain();
	virtual bool isInLava();
	virtual bool isUnderLiquid(const Material*) const;
	virtual float getShadowRadius() const;
	virtual void makeStuckInWeb();
	virtual float getHeadHeight() const;
	virtual float getShadowHeightOffs();
	virtual bool isSkyLit(float);
	virtual float getBrightness(float);
	virtual bool interactPreventDefault();
	virtual void interactWithPlayer(Player*);
	virtual bool canInteractWith(Player*);
	virtual std::string getInteractText(Player*);
	virtual void playerTouch(Player*);
	virtual void push(Entity&);
	virtual void push(float, float, float);
	virtual bool isImmobile();
	virtual bool isSilent();
	virtual bool isPickable();
	virtual bool isPushable();
	virtual bool isShootable();
	virtual bool isSneaking();
	virtual bool isAlive();
	virtual bool isOnFire() const;
	virtual bool isCreativeModeAllowed();
	virtual bool isSurfaceMob() const;
	virtual bool shouldRenderAtSqrDistance(float);
	virtual void hurt(EntityDamageSource&, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void onLightningHit();
	virtual void handleEntityEvent(EntityEvent);
	virtual int getPickRadius();
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(const ItemInstance&, float);
	virtual void awardKillScore(Entity*, int);
	virtual void setEquippedSlot(int, int, int);
	virtual void setEquippedSlot(int, const ItemInstance&);
	virtual void save(CompoundTag&);
	virtual void saveWithoutId(CompoundTag&);
	virtual void load(const CompoundTag&);
	virtual void loadLinks(const CompoundTag&, std::vector<EntityLink, std::allocator<EntityLink>>&);
	virtual int getEntityTypeId() const = 0;
	virtual void queryEntityRenderer();
	virtual void getSourceUniqueID();
	virtual void setOnFire(int);
	virtual AABB getHandleWaterAABB() const;
	virtual void handleInsidePortal();
	virtual int getPortalCooldown() const;
	virtual int getPortalWaitTime() const;
	virtual DimensionId getDimensionId() const;
	virtual void changeDimension(DimensionId);
	virtual void changeDimension(ChangeDimensionPacket&);
	virtual Player* getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void setSize(float, float);
	virtual void setPos(EntityPos*);
	virtual void outOfWorld();
	virtual void markHurt();
	virtual void burn(int);
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(const CompoundTag*) = 0;
	virtual void addAdditionalSaveData(CompoundTag*) = 0;
	virtual void playStepSound(int, int, int, int);
	virtual void checkInsideTiles(float);
	virtual void pushOutOfTiles(float, float, float);
	virtual void _updateWaterState();
	virtual void _doWaterSplashEffect();
	virtual void _updatePortalState();
	virtual void onTileCollision(int);
	virtual void playSound(const std::string&, float, float);
	virtual void onSynchedDataUpdate(int);
	virtual bool canAddRider(Entity&) const;
	virtual void sendMotionPacketIfNeeded();
	virtual void stopRiding(bool);
	virtual void* buildDebugInfo(std::string&) const;
};

typedef std::vector<Entity*> EntityList;
