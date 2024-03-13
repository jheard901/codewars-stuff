
//from https://www.kvraudio.com/forum/viewtopic.php?t=281238
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream> //cin, cout
#include <stdio.h> //printf

#include <string>
//#include <cstring>

//codewars problem of reversing a string
std::string reverseString(std::string str)
{
	//abandon using char arrays for this. just stick to strings... https://stackoverflow.com/questions/21022644/how-to-get-the-real-and-total-length-of-char-char-array
	/*
	char* strArr = new char[str.length() - 1];
	strcpy(strArr, str.c_str());
	
	char* newArr = new char[str.length() - 1];
	//int arrPos = 0;
	int arrLength = sizeof(strArr) / sizeof(strArr[0]);
	
	for (int i = 0; i < arrLength; i++)
	{
		newArr[i] = strArr[arrLength - i];
		//arrPos++;
	}
	*/
	
	std::string newStr = str;

	for (int i = 0; i < str.length(); i++)
	{
		newStr[i] = str[str.length() - i - 1];
	}

	return newStr;
}


int main()
{
	//begin here
	std::cout << reverseString("hello world");
	
	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}

