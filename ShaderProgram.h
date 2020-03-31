#pragma once
#include "glm/gtc/type_ptr.hpp"

class GlShader;

/// <summary>
/// Class represents shader program object.
/// </summary>
class ShaderProgram : public enable_shared_from_this<ShaderProgram>
{
public:
	/// <summary>
	/// Contruct shader program.
	/// Do not use it directly. Use static method ShaderProgram::create()
	/// </summary>
	ShaderProgram();

	/// <summary>
	/// Creates object dynamically.
	/// </summary>
	/// <returns>Newly created object.</returns>
	static shared_ptr<ShaderProgram> create() {
		return make_shared<ShaderProgram>();
	}

	/// <summary>
	/// Terminates shader program.
	/// </summary>
	virtual ~ShaderProgram();

	/// <summary>
	/// Adds shader to this program.
	/// </summary>
	/// <param name="shader">Shader to add.</param>
	void addShader(GlShader& shader);

	/// <summary>
	/// Links shaders.
	/// </summary>
	void link();

	/// <summary>
	/// Uses shader program.
	/// </summary>
	void use();

	/// <summary>
	/// Sends data to uniform variable inside the shader.
	/// </summary>
	/// <param name="valName">Name of the uniform variable.</param>
	/// <param name="value">Value of the variable.</param>
	template<class T>
	void setUniform(const string& valName, const T& value) {
		
		use();//to update values

		if constexpr (is_same<T, mat4>::value) {
			auto location=glGetUniformLocation(id, valName.c_str());
			glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
		}
		else {
			static_assert(false, "value argument must be mat4 type");
		}
	}
	
	bool isLinked() const;
private:

	bool bLinked = false;

	/// <summary>
	/// Id of the shader program.
	/// </summary>
	GLuint id=0;
};

