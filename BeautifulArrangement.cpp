//	526. Beautiful Arrangement
//
//	Suppose you have N integers from 1 to N.
//	We define a beautiful arrangement as an array that is constructed by these N numbers successfully 
//	if one of the following is true for the ith position(1 <= i <= N) in this array:
//
//	The number at the ith position is divisible by i.
//	i is divisible by the number at the ith position.
//	Now given N, how many beautiful arrangements can you construct ?
//
//	Example 1 :
//	Input : 2
//	Output : 2
//	Explanation :
//	The first beautiful arrangement is[1, 2] :
//	Number at the 1st position(i = 1) is 1, and 1 is divisible by i(i = 1).
//	Number at the 2nd position(i = 2) is 2, and 2 is divisible by i(i = 2).
//	The second beautiful arrangement is[2, 1]:
//	Number at the 1st position(i = 1) is 2, and 2 is divisible by i(i = 1).
//	Number at the 2nd position(i = 2) is 1, and i(i = 2) is divisible by 1.
//
//	Note :
//	N is a positive integer and will not exceed 15.
//
//	Written by Zhanran Tang @ 8/30/2017
//
//	Ideas: Backtracking.
//	Complexity: O(k) in time. k is the number of arrangements. O(n) in space.
//	Notes:
//		1. boolean vector will be faster than hashset.
//		2. Start from the largest number with largest index will be much more efficient than start from the smallest.

#include "Header.h"

using namespace std;

void backTracking(int curpos, int N, vector<bool> &used, int &res)
{
	if (curpos <= 0)
		res++;
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (!used[i])
			{
				if ((i%curpos == 0) || (curpos%i == 0))
				{
					used[i] = true;
					backTracking(curpos - 1, N, used, res);
					used[i] = false;
				}
			}
		}
	}
}
int countArrangement(int N)
{
	int res = 0;
	vector<bool> used(N + 1, false);
	backTracking(N, N, used, res);
	return res;
}

int main()
{
	cout << countArrangement(15) << endl;
	system("pause");
	return 0;
}