#pragma once
#include "glad.h"

class VertexAttributePtr
{
public:
	VertexAttributePtr(GLuint index, GLint size, GLsizei strideSize, GLuint offset=0);
	
private:
	GLuint id;
};

