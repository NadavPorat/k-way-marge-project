#pragma once
#include "General.h"


namespace kway
{

	class UI
	{
		public:

			int GetIntFromeUser(string i_MsgToUser);

			void GatInputFile(ifstream& inFileStream, int* arr, int sizeArr);

			void ConverStrToInt(string str, int& out);

			ifstream OpenInputFile(string i_MsgToUser);

			ofstream OpenOutFile(string i_MsgToUser);

			void WriteToOutFile(int* i_OutArr, int i_SizeArr, ofstream& i_OutFile);
	
	};

}