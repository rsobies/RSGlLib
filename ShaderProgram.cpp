#include "pch.h"
#include "ShaderProgram.h"
#include "glad.h"
#include <assert.h>
#include "GlShader.h"

ShaderProgram::ShaderProgram()
{
	programId = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(programId);
}

void ShaderProgram::addShader(GlShader& shader)
{
	glAttachShader(programId, shader.getId());
	shader.setShaderProgram(shared_from_this());
}

void ShaderProgram::use()
{
	glUseProgram(programId);
}

void ShaderProgram::link()
{
	glLinkProgram(programId);

	int success;
	glGetProgramiv(programId, GL_LINK_STATUS, &success);
	assert(success);
	//if (!success) {
		//glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		
	//}
}
