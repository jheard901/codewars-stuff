
#include <iostream> //cin, cout
#include <stdio.h> //printf

/*
Code Wars kata

Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}

*/

#include <vector>

std::vector<int> move_zeroes(const std::vector<int>& input) 
{
	std::vector<int> rInput = input;
	int zCounter = 0; //zero counter

	for (int i = 0; i < rInput.size(); i++)
	{
		if (rInput[i] == 0)
		{
			zCounter++;
			rInput.erase(rInput.begin() + i);
			i = 0;
		}
	}

	if (zCounter)
	{
		for (int i = 0; i < zCounter; i++)
		{
			rInput.push_back(0);
		}
	}

	return rInput;
}


int main()
{
	//begin here
	std::cout << "The following vectors with moved zeroes show their output below...\n\n";
	std::vector<int> sample1 = { 9, 1, 0, 9, 0, 1, 1 };
	std::vector<int> sample2 = { 0, 1, 0, 0, 0, 1, 1 };
	std::vector<int> sample3 = { 0, 0, 0 };
	std::vector<int> sample4 = { 1, 2, 3 };

	//sample 1
	std::cout << "[ 9, 1, 0, 9, 0, 1, 1 ]\n";
	std::vector<int> rSample1 = move_zeroes(sample1);
	std::cout << "[ ";
	for (int i = 0; i < rSample1.size(); i++)
	{
		std::cout << rSample1[i] << ", ";
	}
	std::cout << "]" << std::endl << std::endl;

	//sample 2
	std::cout << "[ 0, 1, 0, 0, 0, 1, 1 ]\n";
	std::vector<int> rSample2 = move_zeroes(sample2);
	std::cout << "[ ";
	for (int i = 0; i < rSample2.size(); i++)
	{
		std::cout << rSample2[i] << ", ";
	}
	std::cout << "]" << std::endl << std::endl;

	//sample 3
	std::cout << "[ 0, 0, 0 ]\n";
	std::vector<int> rSample3 = move_zeroes(sample3);
	std::cout << "[ ";
	for (int i = 0; i < rSample3.size(); i++)
	{
		std::cout << rSample3[i] << ", ";
	}
	std::cout << "]" << std::endl << std::endl;

	//sample 4
	std::cout << "[ 1, 2, 3 ]\n";
	std::vector<int> rSample4 = move_zeroes(sample4);
	std::cout << "[ ";
	for (int i = 0; i < rSample4.size(); i++)
	{
		std::cout << rSample4[i] << ", ";
	}
	std::cout << "]" << std::endl << std::endl;


	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}