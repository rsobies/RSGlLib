#include "pch.h"
#include "GlShader.h"
#include <assert.h>
#include "ShaderProgram.h"


GlShader::GlShader(GLenum shaderType)
{
	id = glCreateShader(shaderType);
	assert(id != 0);
}

void GlShader::setSourcCode(const string& sourceCode)
{
	auto cSource = sourceCode.c_str();
	glShaderSource(id, 1, &cSource, nullptr);
	glCompileShader(id);

	int  success;
	//char infoLog[512];
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	assert(success);
	//if (!success)
	//{
		//glGetShaderInfoLog(shaderId, 512, nullptr, infoLog);
		//int kk = 0;
		//std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	//}
	
}

GlShader::~GlShader()
{
	if (id != 0) {
		glDeleteShader(id);
	}
}

GLuint GlShader::getId() const
{
	return id;
}

void GlShader::setShaderProgram(shared_ptr<ShaderProgram> shProg)
{
	shaderPtr = shProg;
	onProgramSet();
}
