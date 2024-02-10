// File:						UIWindow.h
// Developer:					Mehrbod Molla Kazemi
// Year:						2024

//								This file stores information about creating and manipulating GLFW graphical windows.

#ifndef							_MEL_UI_WINDOW_H_
#define							_MEL_UI_WINDOW_H_

//								OpenGL includes.
#include						<glad/glad.h>
#include						<GLFW/glfw3.h>

//								Library Includes.
#include						<vector>

//								My Includes.
#include						"UIBase.h"
#include						"Diagnostic.h"

namespace						Mel
{
	namespace					GUI
	{
		
		// A class for creating a GLFW GUI window.
		class					UIWindow
		{
		private:

			// Is GLFW initialized?
			static bool				isGLFWInitialized;

			// GLFW Window Object Handle.
			GLFWwindow*				windowHandle;

			// List of children objects.
			std::vector<UIBase*>	children;

			// Number of created UIWindowObjects.
			static	unsigned int	count_UIWindows;

			//// Window properties. ////
			// Size of window.
			int						window_X;
			int						window_Y;
			int						window_Width;
			int						window_Height;

		public:
			// Default UIWindow ctor.
			UIWindow();

			// Copy UIWindow ctor.
			UIWindow(const UIWindow&);

			// UIWindow Dtor.
			~UIWindow();

			// Display window function (mostly for first time after initialization, further calls may be ignored).
			void Display(int wndWidth, int wndHeight,
					std::string wndTitle, bool isFullscreen);

			// Render window (must be always called in a loop to make application responsive!)
			void Render();
		};

	}
}

#endif
