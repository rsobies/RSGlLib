#include "pch.h"
#include "GLWindow.h"

#include <assert.h>
#include <memory>
#include "VertexBuffer.h"
#include "FragmentShader.h"
#include "VertexShader.h"
#include "ShaderProgram.h"
#include "ElementBufferObj.h"

GLWindow::GLWindow(int width, int height)
{
    GlInitializer glInit(width, height);

    //ustawienie callback do zmiany rozmiaru
    glfwSetFramebufferSizeCallback(glInit.getWin().get(), [](GLFWwindow* window, int _width, int _height) {
        glViewport(0, 0, _width, _height);
    });
    
    FragmentShader framgentShader;
    VertexShader vertShader;  
    
    auto shProgram= ShaderProgram::create();
    shProgram->addShader(vertShader);
    shProgram->addShader(framgentShader);
    shProgram->link();
    //framgentShader.setColor({ 0.0f, 0.5f, 0.0f, 1.0f });

    VertexBuffer buffer(
        { {0.5f,  0.5f, 0.0f},  // top right
        {0.5f, -0.5f, 0.0f},    // bottom right
        {-0.5f, -0.5f, 0.0f}, // bottom left
        {-0.5f,  0.5f, 0.0f},   
        {0.0f,  -0.7f, 0.0f} },
        {   {0, 1, 0},//colors
            {0, 0, 1},
            {1, 0, 0},
         {1, 0, 0},
         {1, 0, 0}
        });
   
    buffer.setIndexes({ 0, 1, 3 ,   // first triangle
                        1, 2, 3,
                        4, 2, 1});

    shProgram->use();

    glClearColor(0.5f, 0.5f, 0.5f, 0.5f);

    while (!glfwWindowShouldClose(glInit.getWin().get()))
    {  
        glClear(GL_COLOR_BUFFER_BIT);
       
        buffer.draw();
        
        glfwSwapBuffers(glInit.getWin().get());
        glfwPollEvents();
    }
}
