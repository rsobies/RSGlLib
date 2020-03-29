#pragma once
#include "glm/gtc/type_ptr.hpp"


class GlShader;

class ShaderProgram : public enable_shared_from_this<ShaderProgram>
{
public:
	ShaderProgram();
	static shared_ptr<ShaderProgram> create() {
		return make_shared<ShaderProgram>();
	}
	virtual ~ShaderProgram();
	void addShader(GlShader& shader);
	void link();
	void use();
	template<class T>
	void setUniform(const string& valName, const T& value) {
		
		use();//to update values

		if constexpr (is_same<T, mat4>::value) {
			auto location=glGetUniformLocation(programId, valName.c_str());
			glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
		}
		else {
			static_assert(false, "value argument must be mat4 type");
		}
	}
	
private:	
	GLuint programId=0;
};

