
#include <iostream> //cin, cout
#include <stdio.h> //printf


/* 

Code Wars kata

Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

array = [[1,2,3],
		 [4,5,6],
		 [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]

For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
		 [8,9,4],
		 [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]

And an ex. of a 4x4

array = [[1,2,3,4],
		 [2,3,4,5],
		 [1,9,8,6],
		 [0,9,8,7]]
snail(array) #=> [1,2,3,4,5,6,7,8,9,0,1,2,3,4,8,9]

NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse the 2-d array in a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array [[]].

*/


#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>>& snail_map) {

	//why does the vector need to be static to be able to see changes made in the IDE? When static, the changes are immediately visible
	std::vector<int> result;


	int MATRIX_SIZE = int(snail_map.size());
	int UP_DOWN_EXPECTED = MATRIX_SIZE - 1;
	int LEFT_RIGHT_EXPECTED = MATRIX_SIZE;
	int upDownTraversed = 0, leftRightTraversed = 0;
	int upDownCount = 0, downUpCount = 0, leftRightCount = 0, rightLeftCount = 0;	
	bool bDirection = true; //true = traverse left/right, false = traverse up/down

	// 0x0 matrix case
	if (snail_map.empty()) { UP_DOWN_EXPECTED = 0; }

	while (upDownTraversed != UP_DOWN_EXPECTED || leftRightTraversed != LEFT_RIGHT_EXPECTED)
	{
		bool bTraversed = false;

		if (bDirection)
		{
			//moving left to right
			if (leftRightTraversed % 2 == 0)
			{				
				//redoing these parts without iterators now...
				for (int i = 0 + leftRightCount; i < MATRIX_SIZE - rightLeftCount; i++)
				{
					//codewars doesn't like this line below - always says memory access error
					//result.push_back(snail_map[leftRightCount][i]);

					//now codewars throwing out another error for below lines: vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)					
					//result.push_back(snail_map.at(leftRightCount).at(i));
					//result.insert(result.end(), snail_map[leftRightCount].at(i)); //still same error

					//in code wars, the solution was to add this line of code below to get it to work
					if (snail_map[leftRightCount].empty()) { return result; }
					result.push_back(snail_map[leftRightCount].at(i));					
					bTraversed = true;
				}

				if (bTraversed)
				{
					leftRightCount++;
					leftRightTraversed++;
					bDirection = false;
				}

			}
			//moving right to left
			else
			{
				for (int i = MATRIX_SIZE - 2 - rightLeftCount; i > -2 + leftRightCount; i--)
				{
					result.push_back(snail_map[MATRIX_SIZE - 1 - rightLeftCount][i]);
					bTraversed = true;
				}

				if (bTraversed)
				{
					rightLeftCount++;
					leftRightTraversed++;
					bDirection = false;
				}

			}
		}
		else
		{
			//moving from top to bottom
			if (upDownTraversed % 2 == 0)
			{
				for (int i = 0 + leftRightCount; i < MATRIX_SIZE - downUpCount; i++)
				{
					result.push_back(snail_map[i][MATRIX_SIZE - 1 - upDownCount]);
					bTraversed = true;
				}

				if (bTraversed)
				{
					upDownCount++;
					upDownTraversed++;
					bDirection = true;
				}

			}
			//moving from bottom to top
			else
			{
				for (int i = MATRIX_SIZE - 1 - rightLeftCount; i > 0 + downUpCount; i--)
				{
					result.push_back(snail_map[i][0 + downUpCount]);
					bTraversed = true;
				}

				if (bTraversed)
				{
					downUpCount++;
					upDownTraversed++;
					bDirection = true;
				}

			}
		}
	}

	return result;
}


int main()
{
	// 3x3
	std::vector<int>	sam1 = { 1,2,3 },
						sam2 = { 8,9,4 },
						sam3 = { 7,6,5 };
	std::vector<std::vector<int>> map3x3 = { sam1, sam2, sam3 };

	// 2x2
	std::vector<int>	samp1 = { 9,8 },
						samp2 = { 7,6 };
	std::vector<std::vector<int>> map2x2 = { samp1, samp2 };

	// 1x1
	std::vector<int>	sa1 = { 4 };
	std::vector<std::vector<int>> map1x1 = { sa1 };

	// 0x0
	std::vector<std::vector<int>> map0x0 = { };

	// 6x6
	std::vector<int>	s1 = { 1,1,1,1,1,1 },
						s2 = { 2,2,2,2,2,2 },
						s3 = { 3,3,3,3,3,3 },
						s4 = { 4,4,4,4,4,4 },
						s5 = { 5,5,5,5,5,5 },
						s6 = { 6,6,6,6,6,6 };
	std::vector<std::vector<int>> map6x6 = { s1, s2, s3, s4, s5, s6 };


	//begin here
	std::vector<int>	result0x0 = snail(map0x0),
						result1x1 = snail(map1x1),
						result2x2 = snail(map2x2),
						result3x3 = snail(map3x3),
						result6x6 = snail(map6x6);
	
	//driver
	std::cout << "0x0 result:\n";
	for (int i = 0; i < result0x0.size(); i++)
	{
		std::cout << result0x0[i] << ",";
	}
	std::cout << "\n\n";

	std::cout << "1x1 result:\n";
	for (int i = 0; i < result1x1.size(); i++)
	{
		std::cout << result1x1[i] << ",";
	}
	std::cout << "\n\n";

	std::cout << "2x2 result:\n";
	for (int i = 0; i < result2x2.size(); i++)
	{
		std::cout << result2x2[i] << ",";
	}
	std::cout << "\n\n";

	std::cout << "3x3 result:\n";
	for (int i = 0; i < result3x3.size(); i++)
	{
		std::cout << result3x3[i] << ",";
	}
	std::cout << "\n\n";

	std::cout << "6x6 result:\n";
	for (int i = 0; i < result6x6.size(); i++)
	{
		std::cout << result6x6[i] << ",";
	}
	std::cout << "\n\n";


	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}