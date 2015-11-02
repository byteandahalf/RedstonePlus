#pragma once

#include <memory>
#include <unordered_set>

#include "ParticleType.h"

class Difficulty;
class LevelStorage;
class LevelChunk;
class Player;
class Entity;
class LevelSettings;
class TilePos;
class Vec3;
class FullTile;
class LightLayer;
class TileSource;
class EntityDamageSource;
class SoundPlayer;


class TileSourceListener {
public:
	virtual ~TileSourceListener();
	virtual void onSourceCreated(TileSource*);
	virtual void onSourceDestroyed(TileSource*);
	virtual void onTilesDirty(TileSource*, int, int, int, int, int, int);
	virtual void onAreaChanged(TileSource&, const TilePos&, const TilePos&);
	virtual void onTileChanged(TileSource*, const TilePos&, FullTile, FullTile, int);
	virtual void onBrightnessChanged(TileSource&, const TilePos&);
	virtual void onTileEntityChanged(TileSource&, TileEntity&);
	virtual void onTileEntityRemoved(TileSource&, std::unique_ptr<TileEntity, std::default_delete<TileEntity>>);
	virtual void onTileEvent(TileSource*, int, int, int, int, int);
};

class Level : public TileSourceListener {
public:
	Level(SoundPlayer&, std::unique_ptr<LevelStorage>, const std::string&, const LevelSettings&, bool);

	virtual ~Level();
	virtual void onSourceCreated(TileSource*);
	virtual void onSourceDestroyed(TileSource*);
	virtual void onTileChanged(TileSource*, const TilePos&, FullTile, FullTile, int);
	virtual void addEntity(std::unique_ptr<Entity, std::default_delete<Entity>>);
	virtual void addPlayer(Player*);
	virtual void addGlobalEntity(std::unique_ptr<Entity, std::default_delete<Entity>>);
	virtual void onPlayerDeath(Player&, const EntityDamageSource&);
	virtual void tick();
	virtual void directTickEntities(TileSource&);
	virtual void updateSleepingPlayerList();
	virtual void setDifficulty(Difficulty);
	virtual void runLightUpdates(TileSource&, const LightLayer&, const TilePos&, const TilePos&);
	virtual void onNewChunkFor(Player&, LevelChunk&);
	virtual void onChunkLoaded(LevelChunk&);
	virtual void removeEntity(std::unique_ptr<Entity, std::default_delete<Entity>>&&);
	virtual void removeEntity(Entity&);
	virtual void onAppSuspended();

	bool addParticle(ParticleType, const Vec3&, const Vec3&, int);
	void playSound(float, float, float, const std::string&, float, float);
};
