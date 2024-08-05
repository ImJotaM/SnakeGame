#pragma once
#include "Basics.h"
#include "Window.h"
#include "Shape.h"

namespace dep {

	class Renderer {

	public:

		Renderer() = default;
		~Renderer() { SDL_DestroyRenderer(renderer); };

		void Config(int index, Uint32 Flags);
		void Init(Window& window);

		void Clear(Color color = { 0x0, 0x0, 0x0, 0xFF });
		void Draw(Shape shape);
		void RenderPresent() { SDL_RenderPresent(renderer); }

	private:

		struct RenData {

			int index = -1;
			Uint32 Flags = SDL_RENDERER_PRESENTVSYNC;

		};

		WinData TargetWindowData;
		RenData rendata;

		SDL_Renderer* renderer = nullptr;

	};

}
