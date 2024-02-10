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
		typedef struct TransformStruct
		{
		public: 
			// Translation (Positional) values.
			float translationX, translationY, translationZ;

			// Rotation values.
			float rotationX, rotationY, rotationZ;

			// Scale values.
			float scaleX, scaleY, scaleZ;
		} Transform;

		// Structure for holding an x, y, z point in space.
		typedef struct PointStruct
		{
		public:
			float x, y, z;
		} Point;

		

		// Base abstract class (inteface) for all UI objects. This class cannot be instantiated.
		class UIBase
		{
		private:
			// The transform of the object.
			Transform transform;

		public:
			
			// Abstract DRAW function.
			virtual void Draw() = 0;
		};
	}
}

#endif
