#include "pch.h"
#include "GLWindow.h"

#include <assert.h>
#include <memory>
#include "VertexBuffer.h"
#include "FragmentShader.h"
#include "VertexShader.h"
#include "ShaderProgram.h"
#include "ElementBufferObj.h"
#include "GLTexture.h"

GLWindow::GLWindow(int width, int height)
{
    GlInitializer glInit(width, height);

    //ustawienie callback do zmiany rozmiaru
    glfwSetFramebufferSizeCallback(glInit.getWin().get(), [](GLFWwindow* window, int _width, int _height) {
        glViewport(0, 0, _width, _height);
        });

    FragmentShader framgentShader;
    VertexShader vertShader;

    auto shProgram = ShaderProgram::create();
    shProgram->addShader(vertShader);
    shProgram->addShader(framgentShader);
    shProgram->link();


    VertexBuffer buffer(
        {
            {0.5f,  0.5f, 0.0f},  // top right
            {0.5f, -0.5f, 0.0f},    // bottom right
            {-0.5f, -0.5f, 0.0f},
            {-0.5f, 0.5f, 0.0f}// bottom left
        },
        /*
        {   {1, 1, 1},//colors
            {1, 1, 1},
            {1, 1, 1}
        },*/
        {//text
            {1, 1},  // lower-left corner  
            {1, 0},  // lower-right corner
            {0, 0},
            {0, 1}
        });

    buffer.setIndexes({ 0, 1, 2,
                        0, 3, 2 });

    GLTexture texture;
    texture.loadFromFile("..\\..\\tekstura.jpg");

    shProgram->use();

    glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
    glEnable(GL_DEPTH_TEST);

    mat4 view(1.0f);
    view = translate(view, { 0.0f, 0.0f, -3.0f});
    vertShader.setViewMat(view);

    vertShader.setDefaultPerspective(width, height);

    while (!glfwWindowShouldClose(glInit.getWin().get()))
    {  
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mat4 trans = mat4(1.0f);
        trans = rotate(trans, (float)glfwGetTime(), { 1, 0, 0 });
        vertShader.setWorldMat(trans);
       
        buffer.draw();
        
        glfwSwapBuffers(glInit.getWin().get());
        glfwPollEvents();
    }
}
