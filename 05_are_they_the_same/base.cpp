
#include <iostream> //cin, cout
#include <stdio.h> //printf

#include <vector>

/*
Code wars problem "Are they the same?"

Given two arrays a and b write a function comp(a, b) (orcompSame(a, b)) 
that checks whether the two arrays have the "same" elements, with the 
same multiplicities (the multiplicity of a member is the number of times
it appears). "Same" means, here, that the elements in b are the elements
in a squared, regardless of the order.
*/


class Same {
private:
	static int sq(int n)
	{
		return n * n;
	}
public:
	static bool comp(std::vector<int>& a, std::vector<int>& b) {
		
		//check list sizes match
		if (a.size() != b.size())
		{
			return false;
		}

		//create modifiable copy of b https://stackoverflow.com/questions/644673/is-it-more-efficient-to-copy-a-vector-by-reserving-and-copying-or-by-creating-a
		std::vector<int> bCopy = b;

		//loop through list A elements to validate their square exists in B https://dev.to/vikramvee/three-different-ways-to-iterate-vectors-in-c-using-for-keyword-3871
		bool found = false;
		int itr = 0; //iterator

		//loop through each item in list A
		for (int item : a)
		{			
			itr = 0;
			found = false;

			//loop through each item in list B until we find the square of current value, if not found then function returns false
			for (int nItem : bCopy)
			{
				if (sq(item) == nItem)
				{
					found = true;
					bCopy.erase(bCopy.begin()+itr);
					break;
				}
				itr++;
			}
			if (!found)
			{
				return false;
			}
		}

		return true;
	}
};

int main()
{
	//ex 1
	std::vector<int> a = { 121, 144, 19, 161, 19, 144, 19, 11 };
	std::vector<int> b = { 14641, 20736, 361, 25921, 361, 20736, 361, 121 };

	//ex 2
	std::vector<int> c = { 1, 9, 15, 5, 1, 9, 10, 11 };
	std::vector<int> d = { 121, 100, 81, 1, 25, 225, 4, 1 };

	//where 1 = true and 0 = false
	std::cout << "Does ex.1 A squared = B? " << Same::comp(a, b) << std::endl;
	std::cout << "Does ex.2 A squared = B? " << Same::comp(c, d) << std::endl;

	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}