#include "pch.h"
#include "GlInitializer.h"
#include <assert.h>

GlInitializer::GlInitializer(int widht, int height)
{
    assert(glfwInit() == GLFW_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glWin_ptr = unique_ptr<GLFWwindow, void(*)(GLFWwindow*)>{ glfwCreateWindow(widht, height, "LearnOpenGL", nullptr, nullptr), &glfwDestroyWindow };

    assert(glWin_ptr != nullptr);

    glfwMakeContextCurrent(glWin_ptr.get());

    assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));
    
}

GlInitializer::~GlInitializer()
{
    glfwTerminate();
}

const GlWinPtr& GlInitializer::getWin() const
{
    return glWin_ptr;
}
