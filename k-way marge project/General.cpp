#include "General.h"

namespace kway
{
	void Run()
	{
		UI userInterface;
		int sizeOfArray = 0;
		int k = 0;

		//~~~~ Get input k and sizeArr from user ~~~~//
		sizeOfArray = userInterface.GetIntFromeUser("Please enter the size of the array: ");
		k = userInterface.GetIntFromeUser("Please enter the k pramter : ");


		//~~~~ Open The Correct File (The input File) by its name ~~~~//

		ifstream inFileStream = userInterface.OpenInputFile("Please enter input file name: ");
		ofstream OutFileStream = userInterface.OpenOutFile("Please enter Out file name: ");
		//~~~~ allocate arr by size given ~~~~//
		int* arr = new int[sizeOfArray];
		//~~~~ read from in file to arr  ~~~~//
		userInterface.GatInputFile(inFileStream, arr, sizeOfArray);
		inFileStream.close();
	
		try
		{
			int* out = SortMergeKArrays(arr, sizeOfArray, k);
			userInterface.WriteToOutFile(out, sizeOfArray, OutFileStream);
			OutFileStream.close();
			delete[] arr;
			delete[] out;
		}
		catch (const char* msg)
		{
			cout<<msg<< endl;
		}
		



	}
}