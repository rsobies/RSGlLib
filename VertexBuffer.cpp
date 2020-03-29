#include "pch.h"
#include "VertexBuffer.h"
#include <assert.h>
#include "VertexAttributePtr.h"

VertexBuffer::VertexBuffer() : GLBuffer(GL_ARRAY_BUFFER)
{
}

VertexBuffer::VertexBuffer(const vector<vec3>& points)
	: VertexBuffer()
{
	setVerticles(points);	
}

VertexBuffer::VertexBuffer(const vector<vec3>& points,
	const vector<vec3>& colors)
	: VertexBuffer()
{
	setVerticles(points, colors);
}

VertexBuffer::VertexBuffer(const vector<vec3>& points,
	const vector<vec2>& texCoords) 
	: VertexBuffer()
{
	setVerticles(points, texCoords);
}

VertexBuffer::VertexBuffer(const vector<vec3>& points,
	const vector<vec3>& colors, 
	const vector<vec2>& texCoords)
	: VertexBuffer()
{
	setVerticles(points, colors, texCoords);
}

void VertexBuffer::setVerticles(const vector<vec3>& points,
	const vector<vec3>& colors,
	const vector<vec2>& texCoords)
{
	auto vertexData = createData(points, colors, texCoords);
	setData(vertexData);

	VertexAttributePtr vertAttrPtr(0, 3, strideSize);

	VertexAttributePtr colorAttrPtr(1, 3, strideSize, 3);

	VertexAttributePtr textAttrPtr(2, 2, strideSize, 6);
}

void VertexBuffer::setVerticles(const vector<vec3>& points,
	const vector<vec2>& texCoords) {

	vector<vec3> colors(points.size());
	for (auto& color : colors) {
		color = { 1.0f, 1.0f, 1.0f };//defult color, white
	}

	setVerticles(points, colors, texCoords);
}

void VertexBuffer::setVerticles(const vector<vec3>& points, 
	const vector<vec3>& colors)
{
	vector<vec2> texCoord;
	for (auto& point : points) {
		texCoord.push_back({ 0, 0});//default
	}
	setVerticles(points, colors, texCoord);
}

void VertexBuffer::setVerticles(const vector<vec3>& points)
{
	vector<vec3> colors(points.size());
	for (auto& color : colors) {
		color = { 1.0f, 1.0f, 1.0f };//defult color, white
	}

	setVerticles(points, colors);
}

void VertexBuffer::bindVAO()
{
	vao.bind();
}

void VertexBuffer::setIndexes(const vector<GLuint>& indexes)
{
	indexesBuffer.setData(indexes);	
}

void VertexBuffer::draw()
{
	assert(indexesBuffer.size() > 0);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_TRIANGLES, indexesBuffer.size(), GL_UNSIGNED_INT, 0);
}

vector<GLfloat> VertexBuffer::createData(const vector<vec3>& points,
	const vector<vec3>& colors,
	const vector<vec2>& textCoords)
{
	assert(points.size() == colors.size());
	assert(points.size() == textCoords.size());

	vector<GLfloat> allVert(points.size() * 8);
	int count = 0;
	
	for (int i = 0; i < points.size(); i++) {
		
		allVert[count++] = points[i].x;
		allVert[count++] = points[i].y;
		allVert[count++] = points[i].z;

		allVert[count++] = colors[i].x;
		allVert[count++] = colors[i].y;
		allVert[count++] = colors[i].z;

		allVert[count++] = textCoords[i].x;
		allVert[count++] = textCoords[i].y;
	}
	return allVert;
}
