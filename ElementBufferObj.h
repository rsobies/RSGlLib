#pragma once
#include "GLBuffer.h"

class ElementBufferObj : public GLBuffer<GLuint>
{
public:
	ElementBufferObj() : GLBuffer(GL_ELEMENT_ARRAY_BUFFER){  };
	
private:	
	
};

