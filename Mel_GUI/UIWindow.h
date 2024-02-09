// File:						UIWindow.h
// Developer:					Mehrbod Molla Kazemi
// Year:						2024

//								This file stores information about creating and manipulating GLFW graphical windows.

#ifndef							_MEL_UI_WINDOW_H_
#define							_MEL_UI_WINDOW_H_

//								OpenGL includes.
#include						<GLFW/glfw3.h>
#include						<glad/glad.h>

namespace						Mel
{
	namespace					GUI
	{
		
		// A class for creating a GLFW GUI window.
		class					UIWindow
		{
		private:

			// GLFW Window Object Handle.
			GLFWwindow*			windowHandle;

		public:
			// Default ctor.
			UIWindow			();

			// Copy ctor.
			UIWindow			(const UIWindow&);



		};

	}
}

#endif
