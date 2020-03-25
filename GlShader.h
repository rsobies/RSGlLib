#pragma once
#include <string>
#include "glad.h"
class ShaderProgram;

class GlShader
{
public:
	GlShader(GLenum shaderType);
	void setSourcCode(const string& sourceCode);
	virtual ~GlShader();
	GLuint getId() const;
	void setShaderProgram(shared_ptr<ShaderProgram> shProg);
private:
	GLuint shaderId = 0;
protected:
	shared_ptr<ShaderProgram> shaderPtr=nullptr;
};

