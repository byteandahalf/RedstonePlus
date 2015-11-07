#pragma once
#include "BaseCircuitComponent.h"

class ConsumerComponent : public BaseCircuitComponent {
public:
	ConsumerComponent();

	virtual ~ConsumerComponent();
	virtual std::string& getBaseType() const;
	virtual std::string& getInstanceType() const;
	virtual bool addSource(CircuitSceneGraph&, const CircuitTrackingInfo&, int&, bool&);
	virtual bool allowConnection(CircuitSceneGraph&, const CircuitTrackingInfo&);
	virtual void evaluate(CircuitSystem&, const BlockPos&);
};