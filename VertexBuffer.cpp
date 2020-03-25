#include "pch.h"
#include "VertexBuffer.h"
#include <assert.h>
#include "VertexAttributePtr.h"

VertexBuffer::VertexBuffer() : GLBuffer(GL_ARRAY_BUFFER)
{
}

VertexBuffer::VertexBuffer(const vector<vector<GLfloat>>& points)
	: VertexBuffer()
{
	setVerticles(points);	
}

VertexBuffer::VertexBuffer(const vector<vector<GLfloat>>& points, const vector<vector<GLfloat>>& colors)
	: VertexBuffer()
{
	setVerticles(points, colors);
}

void VertexBuffer::setVerticles(const vector<vector<GLfloat>>& points, 
	const vector<vector<GLfloat>>& colors)
{
	auto vertexData=createData(points, colors);
	setData(vertexData);
	
	VertexAttributePtr vertAttrPtr(0, 3, strideSize);
	
	VertexAttributePtr colorAttrPtr(1, 3, strideSize, 3);	
}

void VertexBuffer::setVerticles(const vector<vector<GLfloat>>& points)
{
	vector<vector<GLfloat>> colors(points.size());
	for (auto& color : colors) {
		color = { 1, 1, 1 };//defult color, white
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

vector<GLfloat> VertexBuffer::createData(const vector<vector<GLfloat>>& points, const vector<vector<GLfloat>>& colors)
{
	assert(points.size() == colors.size());

	vector<GLfloat> allVert(points.size() * 6);
	int count = 0;
	
	for (int i = 0; i < points.size(); i++) {
		assert(points[i].size() == 3);
		assert(colors[i].size() == 3);
		
		for (int j = 0; j < 3; j++) {
			allVert[count++] = points[i][j];
		}

		for (int j = 0; j < 3; j++) {
			allVert[count++] = colors[i][j];
		}

	}
	return allVert;
}
