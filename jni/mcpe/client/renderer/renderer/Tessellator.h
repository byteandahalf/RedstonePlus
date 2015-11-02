#pragma once
class Vec3;
namespace mce { class MaterialPtr; };

class Tessellator {
public:
	static Tessellator instance;
	
	void begin(int);
	void end(const char*, bool);
	void clear();
	void rotateOffset(float, const Vec3&);
	void addOffset(float, float, float);
	void setOffset(float, float, float);
	void draw(const mce::MaterialPtr&);
	void vertexUV(float, float, float, float, float);
	void color(float, float, float, float);
	void color(int);
};
