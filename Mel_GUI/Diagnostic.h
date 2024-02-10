// File:						Diagnostics.h
// Developer:					Mehrbod Molla Kazemi
// Year:						2024

//								This sole header file contains helper functions for outputting messages to output buffer.

#ifndef		_MEL_DIAGNOSTICS_H_
#define		_MEL_DIAGNOSTICS_H_

//								Library Includes.
#include						<iostream>
#include						<string>

namespace Mel
{
	namespace Diagnostics
	{
		class Logger
		{
		public:
			static void Log_Message_Console(std::string message)
			{
				std::cout << "MESSAGE:\t" << message << std::endl;
			}

			static void Log_Message_Error(std::string message, int errorCode)
			{
				std::cout << "WARNING\t" << errorCode << '\t' << message << std::endl;
			}
		};
	}
}

#endif
