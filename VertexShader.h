#pragma once

#include "GlShader.h"

/// <summary>
/// Representation of vertext shader.
/// </summary>
class VertexShader : public GlShader
{
public:
    /// <summary>
    /// Creates vertext shader.
    /// </summary>
    VertexShader();

    /// <summary>
    /// Sends world matrix to shader.
    /// </summary>
    /// <param name="world">Transform matrix.</param>
    void setWorldMat(const mat4& world);

    /// <summary>
    /// Sends view matrix to shader.
    /// </summary>
    /// <param name="view"></param>
    void setViewMat(const mat4& view);

    /// <summary>
    /// Sends projection matrix to shader.
    /// </summary>
    /// <param name="projection"></param>
    void setProjectionMat(const mat4& projection);

protected:
    void onProgramSet() override;
};

