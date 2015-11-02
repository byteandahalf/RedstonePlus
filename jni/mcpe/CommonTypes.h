#pragma once

#include <stdint.h>

typedef uint_fast8_t DataID;
typedef int_fast8_t FacingID;

struct TileID {
	unsigned char value;
	static const TileID AIR;

	TileID() {
		this->value = 1;
	}

	TileID(unsigned char val) {
		this->value = val;
	}

	TileID(TileID const& other) {
		this->value = other.value;
	}

	bool operator==(unsigned char v) {
		return this->value == v;
	}

	bool operator==(TileID v) {
		return this->value == v.value;
	}

	TileID& operator=(const unsigned char& v) {
		this->value = v;
		return *this;
	}

	operator unsigned char() {
		return this->value;
	}
};

class FullTile {
public:
	static const FullTile AIR;

	TileID id;
	DataID data;

	FullTile(TileID tile, DataID dat) {
		this->id = tile;
		this->data = dat;
	}
};

struct Brightness {
	static uint_fast8_t MIN;
	static uint_fast8_t MAX;
};
