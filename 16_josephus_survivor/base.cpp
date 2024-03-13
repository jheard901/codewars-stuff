
#include <iostream> //cin, cout
#include <stdio.h> //printf

/*

Code Wars kata

In this kata you have to correctly return who is the "survivor",
ie: the last element of a Josephus permutation.

Basically you have to assume that n people are put into a circle
and that they are eliminated in steps of k elements, like this:

n=7, k=3 => means 7 people in a circle
one every 3 is eliminated until one remains
[1,2,3,4,5,6,7] - initial sequence
[1,2,4,5,6,7] => 3 is counted out
[1,2,4,5,7] => 6 is counted out
[1,4,5,7] => 2 is counted out
[1,4,5] => 7 is counted out
[1,4] => 5 is counted out
[4] => 1 counted out, 4 is the last element - the survivor!

The above link about the "base" kata description will give you 
a more thorough insight about the origin of this kind of permutation,
but basically that's all that there is to know to solve this kata.

Notes and tips: using the solution to the other kata to check 
your function may be helpful, but as much larger numbers will be used, 
using an array/list to compute the number of the survivor may be too slow;
you may assume that both n and k will always be >=1.

*/


int josephusSurvivor(int n, int k) {
	
	int i = 1, survivor = 0;

	while (i <= n)
	{
		survivor = (survivor + k) % i;
		i++;
	}

	return survivor + 1;
}


int main()
{
	//begin here
	std::cout << "Josephius survivor for 1337 people eliminating every 4 is... " << josephusSurvivor(1337, 4) << "\n\n";

	std::cout << "Now for some Josephius survivor asserts...\n\n";

	std::cout << "11, 19 should equal 10.\n";
	std::cout << "Actual: " << josephusSurvivor(11, 19) << "\n\n";

	std::cout << "100, 1 should equal 100.\n";
	std::cout << "Actual: " << josephusSurvivor(100, 1) << "\n\n";

	std::cout << "300, 300 should equal 265.\n";
	std::cout << "Actual: " << josephusSurvivor(300, 300) << "\n\n";

	std::cout << "2, 3 should equal 2.\n";
	std::cout << "Actual: " << josephusSurvivor(2, 3) << "\n\n";

	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}