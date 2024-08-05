#pragma once
#include "Basics.h"

namespace dep {

	class Event {

	public:

		void PollEvents();
		template<typename Func, typename... Args>
		void RegisterEvent(Uint32 EventType, Func&& Function, Args&&... args);

	private:

		using event_callback = std::function<void(SDL_Event&)>;

		std::unordered_map<Uint32, event_callback> EventCallBacks;

		SDL_Event e;

	};

	template<typename Func, typename... Args>
	void Event::RegisterEvent(Uint32 EventType, Func&& Function, Args&&... args) {

		auto BoundFunction = [func = std::forward<Func>(Function), ...args = std::forward<Args>(args)](SDL_Event& e) {
			func(e, args...);
			};

		EventCallBacks[EventType] = BoundFunction;
	}

}