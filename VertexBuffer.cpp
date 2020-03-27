#include "pch.h"
#include "VertexBuffer.h"
#include <assert.h>
#include "VertexAttributePtr.h"

VertexBuffer::VertexBuffer() : GLBuffer(GL_ARRAY_BUFFER)
{
}

VertexBuffer::VertexBuffer(const vector<vec3f>& points)
	: VertexBuffer()
{
	setVerticles(points);	
}

VertexBuffer::VertexBuffer(const vector<vec3f>& points,
	const vector<vec3f>& colors)
	: VertexBuffer()
{
	setVerticles(points, colors);
}

void VertexBuffer::setVerticles(const vector<vec3f>& points,
	const vector<vec3f>& colors,
	const vector<vec2f>& texCoords)
{
	auto vertexData = createData(points, colors, texCoords);
	setData(vertexData);

	VertexAttributePtr vertAttrPtr(0, 3, strideSize);

	VertexAttributePtr colorAttrPtr(1, 3, strideSize, 3);

	VertexAttributePtr textAttrPtr(2, 2, strideSize, 6);
}

void VertexBuffer::setVerticles(const vector<vec3f>& points, 
	const vector<vec3f>& colors)
{
	vector<vec2f> texCoord;
	for (auto& point : points) {
		texCoord.push_back({ 0, 0});//default
	}
	setVerticles(points, colors, texCoord);
}

void VertexBuffer::setVerticles(const vector<vec3f>& points)
{
	vector<vec3f> colors(points.size());
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

vector<GLfloat> VertexBuffer::createData(const vector<vec3f>& points,
	const vector<vec3f>& colors,
	const vector<vec2f>& textCoords)
{
	assert(points.size() == colors.size());

	vector<GLfloat> allVert(points.size() * 8);
	int count = 0;
	
	for (int i = 0; i < points.size(); i++) {
		
		auto [x, y, z] = points[i];
		allVert[count++] = x;
		allVert[count++] = y;
		allVert[count++] = z;

		auto [x1, y1, z1] = colors[i];
		allVert[count++] = x1;
		allVert[count++] = y1; 
		allVert[count++] = z1;

		auto [x2, y2] = textCoords[i];
		allVert[count++] = x2;
		allVert[count++] = y2;
	}
	return allVert;
}
