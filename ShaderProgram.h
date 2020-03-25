#pragma once
#include "GlShader.h"
#include "glad.h"

class ShaderProgram : public enable_shared_from_this<ShaderProgram>
{
public:
	ShaderProgram();
	static shared_ptr<ShaderProgram> create() {
		return make_shared<ShaderProgram>();
	}
	virtual ~ShaderProgram();
	void addShader(GlShader& shader);
	void link();
	void use();
	
	void setUniformVar(const string& valName, const vector<GLfloat>& value);

private:
	
	GLuint shaderProgram=0;
};

