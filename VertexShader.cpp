#include "pch.h"
#include "VertexShader.h"

VertexShader::VertexShader() : GlShader(GL_VERTEX_SHADER)
{
    string vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "layout(location = 1) in vec3 aColor;\n"// the color variable has attribute position 1
        "layout (location = 2) in vec2 aTexCoord;\n"
        "out vec3 ourColor;\n" // output a color to the fragment shader
        "out vec2 TexCoord;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "ourColor = aColor;\n"
            "TexCoord = aTexCoord;\n"
        "}";

    GlShader::setSourcCode(vertexShaderSource);
}
