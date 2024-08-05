#pragma once

#include <SDL2/SDL.h>

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>

namespace dep {
	
	struct SintPoint {
		Sint16 x;
		Sint16 y;
	};

	struct Vertex {
		unsigned int x = 0;
		unsigned int y = 0;

		SDL_Point ToPoint() {
			return { static_cast<int>(x), static_cast<int>(y) };
		}

		SintPoint ToSint() {
			return {static_cast<short>(x), static_cast<short>(y)};
		}
	};

	struct Color {
		Uint8 R = 0xFF;
		Uint8 G = 0xFF;
		Uint8 B = 0xFF;
		Uint8 A = 0xFF;
	};
}
