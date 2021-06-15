#include "UI.h"

namespace kway
{
	int UI::GetIntFromeUser(string i_MsgToUser)
	{
		int convartNum = -1;
		string strFromUser;
		cout << i_MsgToUser << endl;
		cin >> strFromUser;
		ConverStrToInt(strFromUser, convartNum);
		
			return convartNum;
	}

	void UI::GatInputFile(ifstream& i_InFileStream, int* i_Arr, int i_SizeOfArr)
	{
		
		int countNumbers = 0;
		string Numstr;
		bool isGoodInput = true;
	
		do
		{
			char ch = ' ';
			if(!i_InFileStream.good())
			{
				isGoodInput = false;
			}
			i_InFileStream.get(ch);

			if (ch == ' '  ) //ch = white space
			{

				i_Arr[countNumbers] = stoi(Numstr);
				countNumbers++;
				Numstr = "";

			}
			else if((ch > '9' )||(ch < '0' && ch != '-'))  /// ch is not a num or '-'
			{
				cout << "worng input";
				exit(1);
			}
			else
			{
				Numstr = Numstr + ch;
			}

		} while (!i_InFileStream.eof());


		if (!isGoodInput || i_SizeOfArr != countNumbers)
		{
			cout << "worng input" << endl;
			exit(1);
		}
	}

	void UI::ConverStrToInt(string str, int& out)
	{
		bool isGood = true;
		int num = 0;

		for (int i = 0; i < str.length(); i++)
		{
			if (!isdigit(str[i]))
			{
				cout << "worng input";
				exit(1);
			}
		}

		num = stoi(str);
		if (num < 1)
		{
			cout << "worng input";
			exit(1);

		}
		else
		{
			out = num;
		}
	}

	ifstream UI::OpenInputFile(string i_MsgToUser)
	{
		string fNameIn;
		ifstream inFileStream;

		cout << i_MsgToUser << endl;
		cin >> fNameIn;

		inFileStream.open(fNameIn);
		if (!inFileStream)
		{
			cout << "worng input" << endl;
			exit(1);
		}

		return inFileStream;
	}

	ofstream UI::OpenOutFile(string i_MsgToUser)
	{
		string fName;
		ofstream ofstream;

		cout << i_MsgToUser << endl;
		cin >> fName;

		ofstream.open(fName);
		if (!ofstream)
		{
			cout << "worng input" << endl;
			exit(1);             
		}
		           
		return ofstream;
	}

	void UI::WriteToOutFile(int* i_OutArr,int i_SizeArr, ofstream& i_OutFile)
	{
		for (int i = 0; i < i_SizeArr; i++)
		{
			i_OutFile << i_OutArr[i];
			i_OutFile << "\n";
		}
	}


}