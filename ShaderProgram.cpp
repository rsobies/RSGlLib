#include "pch.h"
#include "ShaderProgram.h"
#include "glad.h"
#include <assert.h>

ShaderProgram::ShaderProgram()
{
	shaderProgram = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(shaderProgram);
}

void ShaderProgram::addShader(GlShader& shader)
{
	glAttachShader(shaderProgram, shader.getId());
	shader.setShaderProgram(shared_from_this());
}

void ShaderProgram::use()
{
	glUseProgram(shaderProgram);
}

void ShaderProgram::setUniformVar(const string& valName, const vector<GLfloat>& value)
{
	auto valLocation = glGetUniformLocation(shaderProgram, valName.c_str());
	assert(valLocation != -1);

	use();//to update uniform

	switch (value.size()) {
		case 1:
			glUniform1f(valLocation, value[0]);
			break;
		case 2:
			glUniform2f(valLocation, value[0], value[1]);
			break;
		case 3:
			glUniform3f(valLocation, value[0], value[1], value[2]);
			break;
		case 4:
			glUniform4f(valLocation, value[0], value[1], value[2], value[3]);
			break;
	}
}

void ShaderProgram::link()
{
	glLinkProgram(shaderProgram);

	int success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	assert(success);
	//if (!success) {
		//glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		
	//}
}
