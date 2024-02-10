// File:						UIWindow.cpp
// Developer:					Mehrbod Molla Kazemi
// Year:						2024

//								This file implements functions for creating and manipulating GLFW graphical windows.

//								Primary Include.
#include						"UIWindow.h"

//								Statics.
bool							Mel::GUI::UIWindow::isGLFWInitialized = false;
unsigned int					Mel::GUI::UIWindow::count_UIWindows = 0;

void errorCallback(int error, const char* description) {
	Mel::Diagnostics::Logger::Log_Message_Error("GLFW - " + std::string(description), error);
}

// Default UIWindow ctor.
Mel::GUI::UIWindow::UIWindow()
{
	this->windowHandle = NULL;

	// if (!UIWindow::isGLFWInitialized)
	if(count_UIWindows == 0)
	{
		bool tempResult = false;

		// Initialize GLFW.
		tempResult = glfwInit();
		if (!tempResult)
		{
			Diagnostics::Logger::Log_Message_Error("Failed to initialize GLFW!", GLFW_PLATFORM_ERROR);
			return;
		}

		// Set GLFW error callbacks immediately.
		glfwSetErrorCallback(::errorCallback);

		// Initialize OpenGL profile.
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
		// Mac OS-X compatible.
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		UIWindow::isGLFWInitialized = true;
		count_UIWindows++;
	}
}

// Copy UIWindow ctor.
Mel::GUI::UIWindow::UIWindow(const UIWindow & other) 
{ 
	this->windowHandle = NULL;
}

// UIWindow Dtor.
Mel::GUI::UIWindow::~UIWindow()
{
	if (this->windowHandle != NULL)
	{
		glfwDestroyWindow(this->windowHandle);
		this->windowHandle = NULL;
	}

	if (count_UIWindows > 0)
		count_UIWindows--;

	if (count_UIWindows == 0)
		glfwTerminate();
}

// Display window function (mostly for first time after initialization, further calls may be ignored).
void Mel::GUI::UIWindow::Display(int wndWidth, int wndHeight,
	std::string wndTitle, bool isFullscreen)
{
	GLFWmonitor* monitor = (isFullscreen) ? glfwGetPrimaryMonitor() : NULL;

	// Destory previous window if allocated before.
	if (this->windowHandle != NULL)
	{
		glfwDestroyWindow(this->windowHandle);
		this->windowHandle = NULL;
	}

	// Create new window.
	this->windowHandle = glfwCreateWindow(wndWidth, wndHeight, wndTitle.c_str(), monitor, NULL);
	if (this->windowHandle == NULL)
	{
		Diagnostics::Logger::Log_Message_Error("Failed to setup GLFW window.", -1);
		exit(-1);
	}

	// Set class properties.
	glfwGetWindowPos(this->windowHandle, &this->window_X, &this->window_Y);
	glfwGetWindowSize(this->windowHandle, &this->window_Width, &this->window_Height);
}

void Mel::GUI::UIWindow::Render()
{
	// Make current thread context.
	if(glfwGetCurrentContext() != this->windowHandle)
		glfwMakeContextCurrent(this->windowHandle);

	// Poll events.
	glfwPollEvents();
}
