#pragma once
//#include "glad.h"
#include "VertexArrayObj.h"
#include "ElementBufferObj.h"
#include "GLBuffer.h"

/// <summary>
/// Representation of the vertex buffer.
/// </summary>
class VertexBuffer : public GLBuffer<GLfloat>
{
public:
	/// <summary>
	/// Constructs vertex buffer.
	/// </summary>
	VertexBuffer();
	VertexBuffer(const vector<vec3>& points);
	VertexBuffer(const vector<vec3>& points,
		const vector<vec3>& colors);
	VertexBuffer(const vector<vec3>& points,
		const vector<vec3>& colors,
		const vector<vec2>& texCoords);
	VertexBuffer(const vector<vec3>& points,
		const vector<vec2>& texCoords);

	void setVerticles(const vector<vec3>& points,
		const vector<vec3>& colors,
		const vector<vec2>& texCoords);

	void setVerticles(const vector<vec3>& points,	
		const vector<vec2>& texCoords);

	void setVerticles(const vector<vec3>& points,
		const vector<vec3>& colors);

	void setVerticles(const vector<vec3>& points);

	/// <summary>
	/// Binds vertex array object.
	/// </summary>
	void bindVAO();

	/// <summary>
	/// Sends indexes into indexes buffer.
	/// </summary>
	/// <param name="indexes">List of indexes.</param>
	void setIndexes(const vector<GLuint>& indexes);

	/// <summary>
	/// Draws verticles.
	/// </summary>
	void draw();
	
private:
	/// <summary>
	/// Concanates all three lists into one vector.
	/// </summary>
	/// <param name="points">List of points.</param>
	/// <param name="colors">List of colors.</param>
	/// <param name="textCoords">List of texture coordinates.</param>
	/// <returns>Concatanation of all lists.</returns>
	vector<GLfloat> createData(const vector<vec3>& points,
		const vector<vec3>& colors,
		const vector<vec2>& textCoords);

	/// <summary>
	/// Indexes buffer.
	/// </summary>
	ElementBufferObj indexesBuffer;

	/// <summary>
	/// Vertex array object.
	/// </summary>
	VertexArrayObj vao;

	/// <summary>
	/// Number of elements in the buffer.
	/// </summary>
	unsigned int strideSize=8;

};

