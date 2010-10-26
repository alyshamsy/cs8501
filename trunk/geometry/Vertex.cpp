#include <iostream>
#include "Vertex.h"

using namespace std;

Vertex::Vertex() {
}

Vertex::~Vertex() {
}

Vertex::Vertex(double a, double b, double c) {
	this->x = a;
	this->y = b;
	this->z = c;
}

void Vertex::set_vertex(double a, double b, double c) {
	this->x = a;
	this->y = b;
	this->z = c;
}