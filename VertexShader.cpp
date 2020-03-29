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
        "uniform mat4 transform={{1, 0, 0, 0},"
                                "{0, 1, 0, 0},"
                                 "{0, 0, 1, 0},"
                                  "{0, 0, 0, 1}};"
        "void main()\n"
        "{\n"
        "   gl_Position = transform * vec4(aPos, 1.0);\n"
            "ourColor = aColor;\n"
            "TexCoord = aTexCoord;\n"
        "}";

    GlShader::setSourcCode(vertexShaderSource);
}

void VertexShader::setTransformMat(const mat4& translation)
{
    assert(shaderPtr != nullptr);
    
    shaderPtr->setUniform("transform", translation);
}
