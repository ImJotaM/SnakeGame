#include "Window.h"

void dep::Window::Config(std::string Title, int PosX, int PosY, int Width, int Height, Uint32 Flags) {
	windata.Title = Title;
	windata.PosX = PosX, windata.PosY = PosY;
	windata.Width = Width, windata.Height = Height;
	windata.Flags = Flags;
}

void dep::Window::Init() {

	const char* Title = windata.Title.c_str();
	int PosX = windata.PosX, PosY = windata.PosY;
	int Width = windata.Width, Height = windata.Height;
	Uint32 Flags = windata.Flags;

	window = SDL_CreateWindow(Title, PosX, PosY, Width, Height, Flags);
}
