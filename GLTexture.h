#pragma once

/// <summary>
/// Reprsentation of openGl texture.
/// </summary>
class GLTexture
{
public:
	/// <summary>
	/// Creates texture object.
	/// </summary>
	GLTexture();

	/// <summary>
	/// Destroys texture.
	/// </summary>
	~GLTexture();

	/// <summary>
	/// Loads texture from file.
	/// </summary>
	/// <param name="texturePath">Path to texture file.</param>
	void loadFromFile(const string& texturePath);
private:
	/// <summary>
	/// Id of the texture.
	/// </summary>
	GLuint id;
};

