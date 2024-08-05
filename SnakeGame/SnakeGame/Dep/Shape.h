#pragma once
#include "Basics.h"

namespace dep {

	class Shape {

	public:

		Shape() = default;
		Shape(std::vector<Vertex> vertices) { Vertices = vertices; }

		std::vector<Vertex> Vertices;

		Color color;
		bool Fill = false;

	};

	inline Shape Line(std::vector<Vertex> vertices, Color color = { 0x0, 0x0, 0x0, 0xFF }) {
		return Shape(vertices);
	}

}