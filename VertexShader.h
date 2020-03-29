#pragma once

#include "GlShader.h"

class VertexShader : public GlShader
{
public:
    VertexShader();
    void setTransformMat(const mat4& translation);
};

