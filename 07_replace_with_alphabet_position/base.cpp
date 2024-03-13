
#include <iostream> //cin, cout
#include <stdio.h> //printf

#include <string>

/*
Code Wars Problem

In this kata you are required to, given a string, replace every letter with its position in the alphabet.

If anything in the text isn't a letter, ignore it and don't return it.

"a" = 1, "b" = 2, etc.

Example
alphabet_position("The sunset sets at twelve o' clock.")
Should return "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11" ( as a string )


Note, for the equivalent of OR using switch statement you skip the break for the cases
you wish to group together as an OR check. See the below link for details:

https://www.codecademy.com/forum_questions/5562647b9113cb333f00037c

*/



std::string alphabet_position(const std::string& text) {

	//start from the beginning of 'text' and go through each char
	//concatenate valid results into the return string
	std::string resultString = "";

	for (const char& c : text)
	{
		switch (c) {
			case 'a':
			case 'A':
				resultString += "1 ";
				break;
			case 'b':
			case 'B':
				resultString += "2 ";
				break;
			case 'c':
			case 'C':
				resultString += "3 ";
				break;
			case 'd':
			case 'D':
				resultString += "4 ";
				break;
			case 'e':
			case 'E':
				resultString += "5 ";
				break;
			case 'f':
			case 'F':
				resultString += "6 ";
				break;
			case 'g':
			case 'G':
				resultString += "7 ";
				break;
			case 'h':
			case 'H':
				resultString += "8 ";
				break;
			case 'i':
			case 'I':
				resultString += "9 ";
				break;
			case 'j':
			case 'J':
				resultString += "10 ";
				break;
			case 'k':
			case 'K':
				resultString += "11 ";
				break;
			case 'l':
			case 'L':
				resultString += "12 ";
				break;
			case 'm':
			case 'M':
				resultString += "13 ";
				break;
			case 'n':
			case 'N':
				resultString += "14 ";
				break;
			case 'o':
			case 'O':
				resultString += "15 ";
				break;
			case 'p':
			case 'P':
				resultString += "16 ";
				break;
			case 'q':
			case 'Q':
				resultString += "17 ";
				break;
			case 'r':
			case 'R':
				resultString += "18 ";
				break;
			case 's':
			case 'S':
				resultString += "19 ";
				break;
			case 't':
			case 'T':
				resultString += "20 ";
				break;
			case 'u':
			case 'U':
				resultString += "21 ";
				break;
			case 'v':
			case 'V':
				resultString += "22 ";
				break;
			case 'w':
			case 'W':
				resultString += "23 ";
				break;
			case 'x':
			case 'X':
				resultString += "24 ";
				break;
			case 'y':
			case 'Y':
				resultString += "25 ";
				break;
			case 'z':
			case 'Z':
				resultString += "26 ";
				break;
			default:
				break;
		}

	}

	if (resultString == "")
	{
		return resultString;
	}
	else
	{
		//remove space at end of resultString
		resultString.pop_back();
		return resultString;
	}
}

int main()
{
	//begin here
	std::cout << "The following examples will return their number equivalant:\n\n";

	std::cout << "Hol' up.\n";
	std::cout << alphabet_position("Hol' up.\n") << std::endl << std::endl;

	std::cout << "8008 1337\n";
	std::cout << alphabet_position("8008 1337") << std::endl << std::endl;

	std::cout << "?Ans e;x4mp13 s3nt4nc3 fil~d w/ e%r%r%o%R%+\n";
	std::cout << alphabet_position("?Ans e;x4mp13 s3nt4nc3 fil~d w/ e%r%r%o%R%+") << std::endl << std::endl;



	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}