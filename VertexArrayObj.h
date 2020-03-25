#pragma once
#include "glad.h"

class VertexArrayObj
{
public:
	VertexArrayObj();
	virtual ~VertexArrayObj();
	void bind();
private:
	GLuint id;
};

