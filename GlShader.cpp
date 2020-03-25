#include "pch.h"
#include "GlShader.h"
#include <assert.h>
#include "ShaderProgram.h"


GlShader::GlShader(GLenum shaderType)
{
	shaderId = glCreateShader(shaderType);
	assert(shaderId != 0);
}

void GlShader::setSourcCode(const string& sourceCode)
{
	auto cSource = sourceCode.c_str();
	glShaderSource(shaderId, 1, &cSource, nullptr);
	glCompileShader(shaderId);

	int  success;
	//char infoLog[512];
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
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
	if (shaderId != 0) {
		glDeleteShader(shaderId);
	}
}

GLuint GlShader::getId() const
{
	return shaderId;
}

void GlShader::setShaderProgram(shared_ptr<ShaderProgram> shProg)
{
	shaderPtr = shProg;
}
