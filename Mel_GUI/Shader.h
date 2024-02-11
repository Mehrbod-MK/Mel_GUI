// File:						Shader.h
// Developer:					Mehrbod Molla Kazemi
// Year:						2024

//								This file stores information about creating and manipulating shaders in OpenGL.

#ifndef _MEL_SHADER_H_
#define _MEL_SHADER_H_

//								OpenGL includes.
#include						<glad/glad.h>
#include						<GLFW/glfw3.h>

//								C++ Library Includes.
#include						<string>

//								My includes.
#include						"Common.h"

namespace	Mel
{
	namespace	GUI
	{
		// Shader class, used to descibe how an object should be rendered down the graphics pipeline.
		class Shader : public Common::Mel_Object
		{
		private:

			GLuint	shaderProgram_ID;
			GLuint	vertexShader_ID;
			GLuint	fragmentShader_ID;

			// Check Shader compilation errors.
			void	checkShaderCompilationErrors(GLuint, std::string);

		public:

			// Shader Ctor.
			Shader(const char*, const char*);

			// Shader Dtor.
			virtual ~Shader();

			// Load Vertex Shader.
			void	Load_VertexShader(const char*);
			
			// Load Fragment Shader.
			void	Load_FragmentShader(const char*);

			// Use shader for render (called in RENDER LOOP).
			void	Use();

			// Releases all allocated resources by Shader object.
			void	Dispose();
		};
	}
}

#endif

