#include "pch.h"
#include "GLTexture.h"
#include <assert.h>
#include "stb_image.h"

using uniqueImgData = unique_ptr<stbi_uc, void(*)(void*)>;

GLTexture::GLTexture()
{
	glGenTextures(1, &id);
	assert(id != 0);	
}

GLTexture::~GLTexture()
{
	glDeleteTextures(1, &id);
}

void GLTexture::loadFromFile(const string& texturePath)
{
	glBindTexture(GL_TEXTURE_2D, id);

	int width, height, nrChannels;
	
	auto imgData= uniqueImgData{stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0), &stbi_image_free};
	assert(imgData != nullptr);
	

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imgData.get());
	glGenerateMipmap(GL_TEXTURE_2D);
}
