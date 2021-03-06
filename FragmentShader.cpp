#include "pch.h"
#include "FragmentShader.h"
#include <assert.h>
#include "ShaderProgram.h"

FragmentShader::FragmentShader() : GlShader(GL_FRAGMENT_SHADER)
{
    string fragmentSource = "#version 330 core\n"
        "out vec4 FragColor;\n"        
        "in vec3 ourColor;\n"
        "in vec2 TexCoord;\n"
        "uniform sampler2D ourTexture;\n"

        "void main()\n"
        "{\n"
        "   FragColor = texture(ourTexture, TexCoord)* vec4(ourColor, 1.0);\n"
        "}";

    GlShader::setSourcCode(fragmentSource);
}
