#include "Event.h"

void dep::Event::PollEvents() {
	while (SDL_PollEvent(&e)) {

		auto it = EventCallBacks.find(e.type);

		if (it != EventCallBacks.end()) {
			it->second(e);
		}
	}
}
