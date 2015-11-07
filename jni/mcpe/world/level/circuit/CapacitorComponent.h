#pragma once
#include "ProducerComponent.h"

class CapacitorComponent : public ProducerComponent {
public:
	CapacitorComponent();

	virtual ~CapacitorComponent();
	virtual std::string& getBaseType() const;
	virtual std::string& getInstanceType() const;
	virtual int getPoweroutDirection() const;
};