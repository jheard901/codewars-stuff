
#include <iostream> //cin, cout
#include <stdio.h> //printf

/*

Code Wars kata

Alright, detective, one of our colleagues successfully observed our target 
person, Robby the robber. We followed him to a secret warehouse, where we 
assume to find all the stolen stuff. The door to this warehouse is secured
by an electronic combination lock. Unfortunately our spy isn't sure about 
the PIN he saw, when Robby entered it.

The keypad has the following layout:

/---/---/---/
/ 1 / 2 / 3 /
/---/---/---/
/ 4 / 5 / 6 /
/---/---/---/
/ 7 / 8 / 9 /
/---/---/---/
	/ 0 /
	/---/
He noted the PIN 1357, but he also said, it is possible that each of the 
digits he saw could actually be another adjacent digit (horizontally or
vertically, but not diagonally). E.g. instead of the 1 it could also be 
the 2 or 4. And instead of the 5 it could also be the 2, 4, 6 or 8.

He also mentioned, he knows this kind of locks. You can enter an unlimited
amount of wrong PINs, they never finally lock the system or sound the alarm.
That's why we can try out all possible (*) variations.

*possible in sense of: the observed PIN itself and all variations considering
the adjacent digits

Can you help us to find all those variations? It would be nice to have a
function, that returns an array (or a list in Java/Kotlin and C#) of all
variations for an observed PIN with a length of 1 to 8 digits. We could 
name the function getPINs (get_pins in python, GetPINs in C#). But please 
note that all PINs, the observed one and also the results, must be strings,
because of potentially leading '0's. We already prepared some test cases 
for you.

Detective, we are counting on you!

*/

#include <string>
#include <vector>

std::vector<std::string> get_pins(std::string observed) {

	std::vector<std::string> result;

	//the PIN variations
	std::vector<int> One = { 1, 2, 4 };
	std::vector<int> Two = { 1, 2, 3, 5 };
	std::vector<int> Three = { 2, 3, 6 };
	std::vector<int> Four = { 1, 4, 5, 7 };
	std::vector<int> Five = { 2, 4, 5, 6, 8 };
	std::vector<int> Six = { 3, 5, 6, 9 };
	std::vector<int> Seven = { 4, 7, 8 };
	std::vector<int> Eight = { 5, 7, 8, 9, 0 };
	std::vector<int> Nine = { 6, 8, 9 };
	std::vector<int> Zero = { 8, 0 };

	std::vector<std::vector<int>> pinNUMS;

	// if e.g. observed = 1,9,4,5
	/*
	
	1 = 1, 2, 4

	9 = 6, 8, 9

	4 = 1, 4, 5, 7

	5 = 2, 4, 5, 6, 8

	outputs would be 1612, 1812, 1912, 2612, 2812, 2912, and etc...

	Maybe create a digitOne digitTwo, and so on up to a maximum of 8 digit variables

	Based off the number in observed, we could fill each digit variable with the possible
	numbers that could go in that digit.

	each digit could be a std::vector<int>... OR...
	we could create a std::vector<std::vector<int>> and fill it based off the length
	and input provided from observed.

	so, if observed was [1,9,4,5] then 1,2,4 would fill the first vector, 6,8,9 the second,
	1,4,5,7 the third, and 2,4,5,6,8 the fourth.

	*/

	//fill the pin possibilities vector
	for (int i = 0; i < observed.length(); i++)
	{	
		std::string s;
		s.push_back(observed.at(i));

		switch (std::stoi(s))
		{
		case 1:
			pinNUMS.push_back(One);
			break;
		case 2:
			pinNUMS.push_back(Two);
			break;
		case 3:
			pinNUMS.push_back(Three);
			break;
		case 4:
			pinNUMS.push_back(Four);
			break;
		case 5:
			pinNUMS.push_back(Five);
			break;
		case 6:
			pinNUMS.push_back(Six);
			break;
		case 7:
			pinNUMS.push_back(Seven);
			break;
		case 8:
			pinNUMS.push_back(Eight);
			break;
		case 9:
			pinNUMS.push_back(Nine);
			break;
		case 0:
			pinNUMS.push_back(Zero);
			break;
		}
	}

	//now we just need to use the pinNUMS vector to generate all permuations
	//among all the possible numbers in each digit


	return result;
}

int main()
{
	//begin here


	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}