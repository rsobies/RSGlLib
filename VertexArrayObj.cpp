#include "pch.h"
#include "VertexArrayObj.h"

VertexArrayObj::VertexArrayObj()
{
	glGenVertexArrays(1, &id);
	bind();
}

VertexArrayObj::~VertexArrayObj()
{
	//glDeleteVertexArrays(1, &id);
}

void VertexArrayObj::bind()
{
	glBindVertexArray(id);
}
