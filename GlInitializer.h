#pragma once

#include "glad.h"
#include <GLFW/glfw3.h>

using GlWinPtr = unique_ptr<GLFWwindow, void(*)(GLFWwindow*)>;

class GlInitializer
{
public:
	
	GlInitializer(int widht=1, int height=1);
	virtual ~GlInitializer();
	const GlWinPtr& getWin();
private:
	GlWinPtr glWin_ptr =  { nullptr, nullptr };
};

