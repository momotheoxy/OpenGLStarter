#ifndef SHADER____H
#define SHADER____H

#include <GL/glew.h>

#include <string>

class Shader
{
public:
    Shader();
    ~Shader();

    void CreateFromString(const char* vertexCode, const char* fragmentCode);
    void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);
    std::string ReadFile(const char* fileLocation);

    void UseShader();
    void ClearShader();

    GLint GetUniformLocation(const char* uniformName) const
    {
        return glGetUniformLocation(shader, uniformName);
    }

private:
    GLuint shader;

    void CompileShaders(const char* vertexCode, const char* fragmentCode);
    bool AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};

#endif
