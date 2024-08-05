#include "Core.h"

void SnakeGame::Run(){

	dep::Window window;
	window.Init();

	dep::Renderer renderer;
	renderer.Init(window);

	dep::Event event;

	while (true) {

		event.PollEvents();

		renderer.Clear();

		renderer.Draw(dep::Line({{0, 0}, {50, 50}}));

		renderer.RenderPresent();

	}
}
