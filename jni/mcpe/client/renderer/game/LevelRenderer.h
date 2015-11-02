#pragma once
class TileTessellator;
namespace mce { class MaterialPtr; };

class LevelRenderer {
public:
	TileTessellator& _getTileRenderer();
};
