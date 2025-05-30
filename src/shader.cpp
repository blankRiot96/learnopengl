#include "shader.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include <glad/glad.h>


Shader::Shader(const char* vertexPath, const char* fragPath) {
    const char* vertexCode;
    std::string vertexString;
    std::ifstream vertexFile;
    std::stringstream vertexStream;

    vertexFile.open(vertexPath);
    vertexStream << vertexFile.rdbuf();
    vertexString = vertexStream.str();
    vertexCode = vertexString.c_str();

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexCode, NULL);
    glCompileShader(vertexShader);


    const char* fragCode;
    std::string fragString;
    std::ifstream fragFile;
    std::stringstream fragStream;

    fragFile.open(fragPath);
    fragStream << fragFile.rdbuf();
    fragString = fragStream.str();
    fragCode = fragString.c_str();

    unsigned int fragShader;
    fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragCode, NULL);
    glCompileShader(fragShader);


    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragShader);
    glLinkProgram(ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
}

void Shader::use() {
    glUseProgram(ID);
}
