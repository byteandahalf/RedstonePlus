#pragma once
struct BlockPos;
class CircuitTrackingScene;
class CircuitSceneGraph;
class CircuitSystem;
#include <string>

class BaseCircuitComponent {
public:
	BaseCircuitComponent();

	virtual ~BaseCircuitComponent();
	virtual int getStrength() const;
	virtual signed char getDirection() const;
	virtual void setStrength(int);
	virtual void setDirection(signed char);
	virtual std::string& getBaseType() const;
	virtual std::string& getInstanceType() const;
	virtual bool removeSource(const BlockPos&);
	virtual bool addSource(CircuitSceneGraph&, const CircuitTrackingInfo&, int&, bool&);
	virtual bool allowConnection(CircuitSceneGraph&, const CircuitTrackingInfo&);
	virtual void evaluate(CircuitSystem&, const BlockPos&);
	virtual void cacheValues(CircuitSystem&, const BlockPos&);
	virtual void updateDependencies(CircuitSceneGraph&, const BlockPos&);
	virtual bool allowIndirect();

protected:
	bool idk; // 4
	bool noidea; // 5
	bool isProvidingSignal; // 6
	int wut; // 8
	int huh; // 12
	int notaclue; // 16
	int strength; // 20
	signed char direction; // 24
	bool allowAttachments; // 25
	bool isOn; // 26
};
