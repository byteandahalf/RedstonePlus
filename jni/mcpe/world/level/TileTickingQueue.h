#pragma once

class TileID;
class TileSource;
class TilePos;

class TileTickingQueue {
public:
	void add(TileSource*, const TilePos&, TileID, int);
};
