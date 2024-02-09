// File:  UIBase.h
// Developer:  Mehrbod Molla Kazemi
// Year: 2024

// This file stores the information about UIBase abstract interface.

#ifndef _MEL_UI_BASE_H_
#define _MEL_UI_BASE_H_

// MelNGin namespace.
namespace Mel
{
	
	// Namespace for graphical user interfaces.
	namespace GUI
	{

		// Structure for holding the transform information of a graphical object.
		typedef struct Transform
		{
		public: 
			float translationX, translationY, translationZ;
			float rotationX, rotationY, rotationZ;
			float scaleX, scaleY, scaleZ;
		};

		// Base abstract class (inteface) for all UI objects. This class cannot be instantiated.
		class UIBase
		{
		private:
			Transform transform;

		public:
			
			// Abstract DRAW function.
			virtual void Draw() = 0;
		};
	}
}

#endif
