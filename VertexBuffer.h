#pragma once
//#include "glad.h"
#include "VertexArrayObj.h"
#include "ElementBufferObj.h"
#include "GLBuffer.h"

class VertexBuffer : public GLBuffer<GLfloat>
{
public:
	VertexBuffer();
	VertexBuffer(const vector<vector<GLfloat>>& points);
	VertexBuffer(const vector<vector<GLfloat>>& points,
		const vector<vector<GLfloat>>& colors);
	void setVerticles(const vector<vector<GLfloat>>& points,
		const vector<vector<GLfloat>>& colors,
		const vector<vector<GLfloat>>& texCoords);
	void setVerticles(const vector<vector<GLfloat>>& points,
		const vector<vector<GLfloat>>& colors);
	void setVerticles(const vector<vector<GLfloat>>& points);
	void bindVAO();
	void setIndexes(const vector<GLuint>& indexes);
	void draw();
private:
	vector<GLfloat> createData(const vector<vector<GLfloat>>& points,
		const vector<vector<GLfloat>>& colors);
	ElementBufferObj indexesBuffer;	
	VertexArrayObj vao;
	unsigned int strideSize=6;
};

