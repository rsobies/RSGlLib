#pragma once

/// <summary>
/// Representation of vertext attribute pointer.
/// </summary>
class VertexAttributePtr
{
public:
	/// <summary>
	/// Consturcts vertex array attribute pointer.
	/// </summary>
	/// <param name="index">Index of the array.</param>
	/// <param name="size">Size of the array.</param>
	/// <param name="strideSize">Number of elements in the stride</param>
	/// <param name="offset">Offset of </param>
	VertexAttributePtr(GLuint index, GLint size, GLsizei strideSize, GLuint offset=0);
	
private:
	/// <summary>
	/// Id of the object.
	/// </summary>
	GLuint id;
};

