// File:						Shader.cpp
// Developer:					Mehrbod Molla Kazemi
// Year:						2024

//								This file implements functions for creating and manipulating shaders in OpenGL.

//								Primary Include.
#include						"Shader.h"

//								My Includes.
#include						"Common.h"

// Shader Ctor.
Mel::GUI::Shader::Shader(const char* vertexShaderFilePath, const char* fragmentShaderFilePath)
{
	auto vertexShaderData = Common::FileIO::LoadFile(vertexShaderFilePath);
	auto fragmentShaderData = Common::FileIO::LoadFile(fragmentShaderFilePath);

    // Create shaders and compile them.
    this->Load_VertexShader(vertexShaderData.c_str());
    this->Load_FragmentShader(fragmentShaderData.c_str());

    // Create shader program and link it.
    this->shaderProgram_ID = glCreateProgram();
    
    // Link shaders.
    glAttachShader(this->shaderProgram_ID, this->vertexShader_ID);
    glAttachShader(this->shaderProgram_ID, this->fragmentShader_ID);

    // Link program.
    glLinkProgram(this->shaderProgram_ID);
}

// Shader Dtor.
Mel::GUI::Shader::~Shader()
{
    if (this->vertexShader_ID != NULL)
    {
        glDeleteShader(this->vertexShader_ID);
        this->vertexShader_ID = NULL;
    }

    if (this->fragmentShader_ID != NULL)
    {
        glDeleteShader(this->fragmentShader_ID);
        this->fragmentShader_ID = NULL;
    }

    if (this->shaderProgram_ID != NULL)
    {
        glDeleteProgram(this->shaderProgram_ID);
    }
}

// Load Vertex Shader.
void Mel::GUI::Shader::Load_VertexShader(const char* vertShaderContents)
{
	if (this->vertexShader_ID == 0)
		this->vertexShader_ID = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(this->vertexShader_ID, 1, &vertShaderContents, NULL);
	glCompileShader(this->vertexShader_ID);

    this->checkShaderCompilationErrors(this->vertexShader_ID, "VERTEX_SHADER");
}

// Load Fragment Shader.
void Mel::GUI::Shader::Load_FragmentShader(const char* fragShaderContents)
{
    if (this->fragmentShader_ID == 0)
        this->fragmentShader_ID = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(this->fragmentShader_ID, 1, &fragShaderContents, NULL);
    glCompileShader(this->fragmentShader_ID);

    this->checkShaderCompilationErrors(this->fragmentShader_ID, "FRAGMENT_SHADER");
}

// Check Shader compilation errors.
void Mel::GUI::Shader::checkShaderCompilationErrors(GLuint shader, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}

// Use shader for render (called in RENDER LOOP).
void Mel::GUI::Shader::Use()
{
    glUseProgram(this->shaderProgram_ID);
}
