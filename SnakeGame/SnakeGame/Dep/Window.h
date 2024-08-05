#pragma once
#include "Basics.h"

namespace dep {

	struct WinData {

		std::string Title = "Default Title";
		int PosX = SDL_WINDOWPOS_CENTERED, PosY = SDL_WINDOWPOS_CENTERED;
		int Width = 800, Height = 600;
		Uint32 Flags = SDL_WINDOW_SHOWN;

	};

	class Window {

	public:

		Window() = default;
		~Window() { SDL_DestroyWindow(window); }

		void Config(std::string Title,
					int PosX, int PosY,
					int Width, int Height,
					Uint32 Flags);
		void Init();

		SDL_Window* GetWindow() { return window; };

		WinData windata;

	private:

		SDL_Window* window = nullptr;

	};

}