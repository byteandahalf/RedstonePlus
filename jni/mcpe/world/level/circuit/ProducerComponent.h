#pragma once
#include "BaseCircuitComponent.h"

class ProducerComponent : public BaseCircuitComponent {
public:
	ProducerComponent();

	virtual ~ProducerComponent();
	virtual std::string& getBaseType() const;
	virtual std::string& getInstanceType() const;
	virtual bool allowConnection(CircuitSceneGraph&, const CircuitTrackingInfo&);

	void allowAttachments(bool);
};