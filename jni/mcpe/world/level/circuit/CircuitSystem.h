#pragma once
#include <memory>
struct BlockPos;
class BaseCircuitComponent;
#include "CircuitSceneGraph.h"

class CircuitSystem : public CircuitSceneGraph {
public:
	char data_CircuitSystem[12];

	void createComponent(const BlockPos&, signed char, std::unique_ptr<BaseCircuitComponent>);
	void removeComponents(const BlockPos&);
	void setStrength(const BlockPos&, int);
	int getStrength(const BlockPos&);
	signed char getDirection(const BlockPos&);

	void lockGraph(bool);
	bool hasNeighborComponent(const BlockPos&, int);
	bool hasDirectPower(const BlockPos&);
};
