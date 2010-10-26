#ifndef VERTEX_H
#define VERTEX_H

class Vertex {
public:
	Vertex();
	Vertex(double a, double b, double c);
	Vertex(const Vertex& source);
	~Vertex();
	void set_vertex(double a, double b, double c);

	double x, y, z;
};
#endif