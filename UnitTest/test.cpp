#include "pch.h"
#include "MemoryLeakDetector.h"


//#include "../glad.h"
//#include <GLFW/glfw3.h>

#include "../GLWindow.h"
#include "../ShaderProgram.h"
#include "../VertexBuffer.h"
#include "../VertexShader.h"
#include "../FragmentShader.h"
#include "../GLTexture.h"

class RSGLTest : public testing::Test {
public:

private:
    MemoryLeakDetector memoryCheck;
};

TEST_F(RSGLTest, textureTest) {
    GlInitializer init;
    GLTexture texture;
    texture.loadFromFile("..\\..\\tekstura.jpg");
}
TEST_F(RSGLTest, ShaderTest) {
    GlInitializer init;
    FragmentShader fragmentShader;
    VertexShader vertShader;

    auto shProgram = ShaderProgram::create();

    shProgram->addShader(vertShader);
    shProgram->addShader(fragmentShader);   
    shProgram->link();

    //fragmentShader.setColor({ 0.5, 1, 1, 1 });
    shProgram->use();
}

TEST_F(RSGLTest, VertexBufer) {
    GlInitializer init;
    VertexBuffer buffer({ {1, 2, 3} });
    buffer.bindVAO();
}

TEST_F(RSGLTest, WinTest) {
    //new int[3];
    GLWindow win(800, 600);
   
}