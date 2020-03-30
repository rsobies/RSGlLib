#pragma once
#include "GLBuffer.h"

/// <summary>
/// Class represents indexes buffer.
/// </summary>
class ElementBufferObj : public GLBuffer<GLuint>
{
public:
	/// <summary>
	/// Creates inexes buffer.
	/// </summary>
	ElementBufferObj() : GLBuffer(GL_ELEMENT_ARRAY_BUFFER){  };
};

