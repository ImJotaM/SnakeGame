#include "Renderer.h"

void dep::Renderer::Config(int index, Uint32 Flags) {
	rendata.index = index;
	rendata.Flags = Flags;
}

void dep::Renderer::Init(Window& window) {

	int index = rendata.index;
	Uint32 Flags = rendata.Flags;

	renderer = SDL_CreateRenderer(window.GetWindow(), index, Flags);

	TargetWindowData = window.windata;
}

void dep::Renderer::Clear(Color color) {
	SDL_SetRenderDrawColor(renderer, color.R, color.G, color.B, color.A);
	SDL_RenderClear(renderer);
}

void dep::Renderer::Draw(Shape shape) {

	if (shape.Vertices.size() == 1) return;

	if (shape.Vertices.size() == 2) {
		
		Color c = shape.color;
		SDL_SetRenderDrawColor(renderer, c.R, c.G, c.B, c.A);

		int x1 = shape.Vertices[0].x, y1 = shape.Vertices[0].y;
		int x2 = shape.Vertices[1].x, y2 = shape.Vertices[1].y;

		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);

		return;
	}

	if (shape.Fill == false) {

		Color c = shape.color;
		SDL_SetRenderDrawColor(renderer, c.R, c.G, c.B, c.A);

		std::vector<SDL_Point> vertices;

		for (Vertex& point : shape.Vertices)
			vertices.push_back(point.ToPoint());

		vertices.push_back(shape.Vertices.front().ToPoint());

		SDL_RenderDrawLines(renderer, vertices.data(), static_cast<int>(vertices.size()));

	}
	else {
		
		Color c = shape.color;

		std::vector<Sint16> xs;
		std::vector<Sint16> ys;

		for (Vertex& point : shape.Vertices) {
			xs.push_back(point.ToSint().x);
			ys.push_back(point.ToSint().y);
		}

	}
}

