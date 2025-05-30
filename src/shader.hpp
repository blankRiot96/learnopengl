#ifndef SHADER_H
#define SHADER_H


class Shader {
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragPath);
    void use();
};

#endif