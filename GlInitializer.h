#pragma once

#include <GLFW/glfw3.h>

/// <summary>
/// Unique pointer to GLFWwindow
/// </summary>
using GlWinPtr = unique_ptr<GLFWwindow, void(*)(GLFWwindow*)>;

/// <summary>
/// Helper class to initilize open gl.
/// Just make instance of this class to perform initialization.
/// </summary>
class GlInitializer
{
public:
	/// TODO: add title argument to constructor
	/// <summary>
	/// Initilize openGl and creates default window.
	/// </summary>
	/// <param name="widht">Width of the window.</param>
	/// <param name="height">Height of the window.</param>
	GlInitializer(int widht=1, int height=1);

	/// <summary>
	/// Terminates openGl.
	/// </summary>
	virtual ~GlInitializer();

	/// <summary>
	/// Retrives openGl window.
	/// </summary>
	/// <returns>OpenGL window</returns>
	const GlWinPtr& getWin() const;
private:
	/// <summary>
	/// Holding pointer to openGL window.
	/// </summary>
	GlWinPtr glWin_ptr =  { nullptr, nullptr };
};

