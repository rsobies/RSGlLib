#include "pch.h"
#include "VertexAttributePtr.h"

VertexAttributePtr::VertexAttributePtr(GLuint index, GLint size, GLsizei strideSize, GLuint offset)
{
	id = index;
	glVertexAttribPointer(id, size, GL_FLOAT, GL_FALSE, strideSize * sizeof(GLfloat), (void*)(offset* sizeof(GLfloat)));
	glEnableVertexAttribArray(id);

}
