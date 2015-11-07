#pragma once
#include <stdint.h>

typedef uint_fast8_t DataID;
typedef int_fast8_t FacingID;

struct BlockID {
	unsigned char value;
	static const BlockID AIR;

	BlockID() {
		this->value = 1;
	}

	BlockID(unsigned char val) {
		this->value = val;
	}

	BlockID(BlockID const& other) {
		this->value = other.value;
	}

	bool operator==(unsigned char v) {
		return this->value == v;
	}

	bool operator==(BlockID v) {
		return this->value == v.value;
	}

	BlockID& operator=(const unsigned char& v) {
		this->value = v;
		return *this;
	}

	operator unsigned char() {
		return this->value;
	}
};

struct FullBlock {
	static const FullBlock AIR;

	BlockID id;
	DataID data;

	FullBlock(BlockID tile, DataID dat) {
		this->id = tile;
		this->data = dat;
	}
};

struct Brightness {
	static uint_fast8_t MIN;
	static uint_fast8_t MAX;
};
