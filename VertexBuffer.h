#pragma once
//#include "glad.h"
#include "VertexArrayObj.h"
#include "ElementBufferObj.h"
#include "GLBuffer.h"



//using vec2f = tuple<GLfloat, GLfloat>;
//using vec3f = tuple<GLfloat, GLfloat, GLfloat>;


class VertexBuffer : public GLBuffer<GLfloat>
{
public:
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

	void bindVAO();
	void setIndexes(const vector<GLuint>& indexes);
	void draw();
	
private:
	vector<GLfloat> createData(const vector<vec3>& points,
		const vector<vec3>& colors,
		const vector<vec2>& textCoords);
	ElementBufferObj indexesBuffer;	
	VertexArrayObj vao;
	unsigned int strideSize=8;
};

