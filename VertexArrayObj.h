#pragma once

/// <summary>
/// Representation of vertex array object.
/// </summary>
class VertexArrayObj
{
public:
	/// <summary>
	/// Constructs vertex array object.
	/// </summary>
	VertexArrayObj();

	/// <summary>
	/// Destorys the object.
	/// </summary>
	virtual ~VertexArrayObj();

	/// <summary>
	/// Binds the object.
	/// </summary>
	void bind();
private:
	/// <summary>
	/// Id of the object.
	/// </summary>
	GLuint id;
};

