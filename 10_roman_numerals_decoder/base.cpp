
#include <iostream> //cin, cout
#include <stdio.h> //printf

/*

Code Wars kata

Create a function that takes a Roman numeral as its argument and 
returns its value as a numeric decimal integer. You don't need to 
validate the form of the Roman numeral.

Modern Roman numerals are written by expressing each decimal digit
of the number to be encoded separately, starting with the leftmost 
digit and skipping any 0s. So 1990 is rendered "MCMXC" (1000 = M, 900 = CM, 90 = XC) 
and 2008 is rendered "MMVIII" (2000 = MM, 8 = VIII). The Roman numeral
for 1666, "MDCLXVI", uses each letter in descending order.

Example:

solution("XXI"); // => 21
Help:

Symbol    Value
I          1
V          5
X          10
L          50
C          100
D          500
M          1,000

Courtesy of rosettacode.org

*/


#include <string>

bool IsValidRoman(std::string rStr)
{
	// NotLikeThis...

	//check the thousands
	if (rStr == "M") //1000
	{

	}
	else if (rStr == "MM") //2000
	{

	}
	else if (rStr == "MMM") //3000
	{

	}
	//check the hundreds
	else if (rStr == "C") //100
	{

	}
	else if (rStr == "CC") //200
	{

	}
	else if (rStr == "CCC") //300
	{

	}
	else if (rStr == "CD") //400
	{

	}
	else if (rStr == "D") //500
	{

	}
	else if (rStr == "DC") //600
	{

	}
	else if (rStr == "DCC") //700
	{

	}
	else if (rStr == "DCCC") //800
	{

	}
	else if (rStr == "CM") //900
	{

	}
	//check the tens
	else if (rStr == "X") //10
	{

	}
	else if (rStr == "XX") //20
	{

	}
	else if (rStr == "XXX") //30
	{

	}
	else if (rStr == "XL") //40
	{

	}
	else if (rStr == "L") //50
	{

	}
	else if (rStr == "LX") //60
	{

	}
	else if (rStr == "LXX") //70
	{

	}
	else if (rStr == "LXXX") //80
	{

	}
	else if (rStr == "XC") //90
	{

	}
	//check the ones
	else if (rStr == "I") //1
	{

	}
	else if (rStr == "II") //2
	{

	}
	else if (rStr == "III") //3
	{

	}
	else if (rStr == "IV") //4
	{

	}
	else if (rStr == "V") //5
	{

	}
	else if (rStr == "VI") //6
	{

	}
	else if (rStr == "VII") //7
	{

	}
	else if (rStr == "VIII") //8
	{

	}
	else if (rStr == "IX") //9
	{

	}
	else
	{
		return false;
	}

	return true;
}

int CalcValidRoman(std::string rStr)
{
	// NotLikeThis...

	//check the thousands
	if (rStr == "M") //1000
	{
		return 1000;
	}
	else if (rStr == "MM") //2000
	{
		return 2000;
	}
	else if (rStr == "MMM") //3000
	{
		return 3000;
	}
	//check the hundreds
	else if (rStr == "C") //100
	{
		return 100;
	}
	else if (rStr == "CC") //200
	{
		return 200;
	}
	else if (rStr == "CCC") //300
	{
		return 300;
	}
	else if (rStr == "CD") //400
	{
		return 400;
	}
	else if (rStr == "D") //500
	{
		return 500;
	}
	else if (rStr == "DC") //600
	{
		return 600;
	}
	else if (rStr == "DCC") //700
	{
		return 700;
	}
	else if (rStr == "DCCC") //800
	{
		return 800;
	}
	else if (rStr == "CM") //900
	{
		return 900;
	}
	//check the tens
	else if (rStr == "X") //10
	{
		return 10;
	}
	else if (rStr == "XX") //20
	{
		return 20;
	}
	else if (rStr == "XXX") //30
	{
		return 30;
	}
	else if (rStr == "XL") //40
	{
		return 40;
	}
	else if (rStr == "L") //50
	{
		return 50;
	}
	else if (rStr == "LX") //60
	{
		return 60;
	}
	else if (rStr == "LXX") //70
	{
		return 70;
	}
	else if (rStr == "LXXX") //80
	{
		return 80;
	}
	else if (rStr == "XC") //90
	{
		return 90;
	}
	//check the ones
	else if (rStr == "I") //1
	{
		return 1;
	}
	else if (rStr == "II") //2
	{
		return 2;
	}
	else if (rStr == "III") //3
	{
		return 3;
	}
	else if (rStr == "IV") //4
	{
		return 4;
	}
	else if (rStr == "V") //5
	{
		return 5;
	}
	else if (rStr == "VI") //6
	{
		return 6;
	}
	else if (rStr == "VII") //7
	{
		return 7;
	}
	else if (rStr == "VIII") //8
	{
		return 8;
	}
	else if (rStr == "IX") //9
	{
		return 9;
	}
	else 
	{
		return 0;
	}
}

int solution(std::string roman) {
		
	int romanResult = 0;
	std::string tempStr = "";

	while (roman != "")
	{
		tempStr = "";

		for (int i = 0; i < roman.size(); i++)
		{
			tempStr += roman[i];

			if (!IsValidRoman(tempStr))
			{
				//remove invalid char
				tempStr.pop_back();

				//add valid roman value for result
				romanResult += CalcValidRoman(tempStr);

				//remove the added value from input string
				roman.erase(0, i);

				//now reset and exit loop
				tempStr = "";
				break;
			}
		}

		//looped through entire input and still valid roman
		if (tempStr != "")
		{
			//add valid roman value for result
			romanResult += CalcValidRoman(tempStr);

			//remove the added value from input string
			roman.erase(0, tempStr.size());
		}
	}

	return romanResult;
}


int main()
{
	//begin here
	std::cout << "Roman Numerals will be translated. Assume they are valid numerals.\n\n";

	std::cout << "XVIII: " << solution("XVIII") << "\n";
	std::cout << "LVII: " << solution("LVII") << "\n";
	std::cout << "MCMXLIII: " << solution("MCMXLIII") << "\n";
	std::cout << "X: " << solution("X") << "\n";
	std::cout << "CDXXIV: " << solution("CDXXIV") << "\n";

	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}