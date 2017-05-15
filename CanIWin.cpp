//	464. Can I Win
//
//	In the "100 game," two players take turns adding, to a running total, any integer from 1..10.
//	The player who first causes the running total to reach or exceed 100 wins.
//
//	What if we change the game so that players cannot re - use integers ?
//
//	For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement 
//	until they reach a total >= 100.
//
//	Given an integer maxChoosableInteger and another integer desiredTotal, 
//	determine if the first player to move can force a win, assuming both players play optimally.
//
//	You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
//
//	Idea: Using DP with each state stored.
//	Complexity: O(2^n)

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<int, bool> storage;

int bools2int(vector<bool> vec)
{
	int res = 1;
	for (int i = 1; i<vec.size(); i++)
	{
		res = res << 1;
		if (vec[i])
			res = res | 1;
	}
	return res;
}

bool play(int desiredTotal, vector<bool> pool)
{
	if (desiredTotal <= 0)
		return false;
	int key = bools2int(pool);
	if (storage.find(key) != storage.end())
		return storage[key];
	for (int i = 1; i<pool.size(); i++)
	{
		if (pool[i])
		{
			pool[i] = false;
			if (!play(desiredTotal - i, pool))
			{
				storage[key] = true;
				pool[i] = true;
				return true;
			}
			pool[i] = true;
		}
	}
	storage[key] = false;
	return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal)
{
	if ((1 + maxChoosableInteger)*maxChoosableInteger / 2 < desiredTotal)
		return false;
	if (desiredTotal <= maxChoosableInteger)
		return true;
	vector<bool> pool(maxChoosableInteger + 1, true);
	return play(desiredTotal, pool);
}

int main()
{
	cout << canIWin(4, 6) << endl;
	system("pause");
	return 0;
}