#pragma once
#include <vector>
#include <string>

namespace Touch {
	class StartMenuScreen {
	public:
		static int currentSplash;
		static std::vector<std::string> mSplashes;
		static std::vector<std::string> pocketpowerSplashes;

		void chooseRandomSplash();
	};
}
