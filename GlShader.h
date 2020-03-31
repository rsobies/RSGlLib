#pragma once

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
	
	GLuint id = 0;
protected:
	shared_ptr<ShaderProgram> shaderPtr=nullptr;
	virtual void onProgramSet() {};	
};

