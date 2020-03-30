#include "pch.h"
#include "VertexShader.h"

VertexShader::VertexShader() : GlShader(GL_VERTEX_SHADER)
{
    string vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;"
        "layout(location = 1) in vec3 aColor;"// the color variable has attribute position 1
        "layout (location = 2) in vec2 aTexCoord;"
        "out vec3 ourColor;" // output a color to the fragment shader
        "out vec2 TexCoord;"
        "uniform mat4 world={{1, 0, 0, 0},"
                                "{0, 1, 0, 0},"
                                 "{0, 0, 1, 0},"
                                  "{0, 0, 0, 1}};"
        "uniform mat4 view={{1, 0, 0, 0},"
        "{0, 1, 0, 0},"
        "{0, 0, 1, 0},"
        "{0, 0, 0, 1}};"

        "uniform mat4 projection={{1, 0, 0, 0},"
        "{0, 1, 0, 0},"
        "{0, 0, 1, 0},"
        "{0, 0, 0, 1}};"

        "void main()\n"
        "{\n"
        "   gl_Position = world * vec4(aPos, 1.0);\n"
            "ourColor = aColor;\n"
            "TexCoord = aTexCoord;\n"
        "}";

    GlShader::setSourcCode(vertexShaderSource);
}

void VertexShader::setWorldMat(const mat4& world)
{
    assert(shaderPtr != nullptr);
    
    shaderPtr->setUniform("world", world);
}

void VertexShader::setViewMat(const mat4& view)
{
    assert(shaderPtr != nullptr);

    shaderPtr->setUniform("view", view);
}

void VertexShader::setProjectionMat(const mat4& projection)
{
    assert(shaderPtr != nullptr);

    shaderPtr->setUniform("projection", projection);
}

void VertexShader::onProgramSet()
{
    mat4 projection;
    projection = perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    setProjectionMat(projection);
}
