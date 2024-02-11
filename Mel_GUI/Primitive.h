// File:						Primitive.h
// Developer:					Mehrbod Molla Kazemi
// Year:						2024

//								This file stores information about creating and manipulating primitives in OpenGL.

#ifndef		_MEL_PRIMITIVE_H_
#define		_MEL_PRIMITIVE_H_

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
		// Class used for manipulating primitives in MelNGin.
		class Primitive : public Common::Mel_Object
		{
		private:
			float*				vertices;
			int*				indices;

			GLsizei				numVertices;
			GLsizei				numIndices;

		public:

			// Primitive default Ctor.
			Primitive();

			// Primitive Dtor.
			virtual ~Primitive();
		};

	}
}

#endif
