// File:						Common.h
// Developer:					Mehrbod Molla Kazemi
// Year:						2024

//								This file stores functions used in common MelNGine namespace.

#ifndef		_MEL_COMMON_H_
#define		_MEL_COMMON_H_

//								C++ Includes.
#include						<fstream>
#include						<iostream>
#include						<string>

namespace Mel
{
	// Common utility functions namespace.
	namespace Common
	{
		// Class related to manipulating files.
		class FileIO
		{
		public:
			static std::string LoadFile(const char* filePath)
			{
				auto file = std::ifstream(filePath);
				if (file)
				{
					file.seekg(0, std::ios::end);
					size_t fileSize = file.tellg();

					std::string binData(fileSize, ' ');
					file.seekg(0);

					file.read(&binData[0], fileSize);

					return binData;
				}

				return "";
			}
		};

		// Base class for every normal-behaved object in MelNGin. This class cannot be instantiated.
		class Mel_Object
		{
		public:

			// Pure virtial method for releasing object's allocated resources.
			virtual void Dispose() = 0;
		};
	}
}

#endif

