#pragma once
#include <string>
#include "glad.h"
#include "ShaderProgram.h"

class GlShader
{
public:
	GlShader(GLenum shaderType);
	void setSourcCode(const string& sourceCode);
	virtual ~GlShader();
	GLuint getId() const;
	void setShaderProgram(shared_ptr<ShaderProgram> shProg);
private:
	virtual void onProgramSet();
	GLuint shaderId = 0;
protected:
	shared_ptr<ShaderProgram> shaderPtr=nullptr;
};

