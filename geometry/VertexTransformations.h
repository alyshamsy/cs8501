#include "VertexArithmetic.h"

class VertexTransformations {
public:
	VertexTransformations();
	~VertexTransformations();
	Vertex* do_vector_translation(Vertex* A, Vertex* input_vector);
	Vertex* do_uniform_scaling(double scalar, Vertex* A);
	Vertex* do_axis_scaling(Vertex* A, char axis, double scaling_value);
private:
	VertexArithmetic* arithmetic;
};