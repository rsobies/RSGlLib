#pragma once

class GLTexture
{
public:
	GLTexture();
	~GLTexture();
	void loadFromFile(const string& texturePath);
private:
	GLuint id;
};

