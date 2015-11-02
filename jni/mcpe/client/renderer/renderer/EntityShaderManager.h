#pragma once
class Entity;

class EntityShaderManager {
public:
	virtual ~EntityShaderManager();
	virtual void* getOverlayColor(Entity&, float) const;
};
