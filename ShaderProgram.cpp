#include "pch.h"
#include "ShaderProgram.h"
#include "glad.h"
#include <assert.h>
#include "GlShader.h"

ShaderProgram::ShaderProgram()
{
	id = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(id);
}

void ShaderProgram::addShader(GlShader& shader)
{
	glAttachShader(id, shader.getId());
	shader.setShaderProgram(shared_from_this());
}

void ShaderProgram::use()
{
	glUseProgram(id);
}

void ShaderProgram::link()
{
	glLinkProgram(id);

	int success;
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	assert(success);
	//if (!success) {
		//glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		
	//}
}
