//	72. Edit Distance
//
//	Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
//
//	You have the following 3 operations permitted on a word :
//
//	a) Insert a character
//	b) Delete a character
//	c) Replace a character
//
//	Written by Zhanran Tang @ 9/5/2017
//
//	Ideas: DP solution.
//		OPT(i,j) is defined as the minimum operations to convert word1[0~i-1] to word2[0~j-1]
//		If word1[i-1] == word2[j-1], OPT(i,j) = OPT(i-1,j-1) as there's no more operations needed.
//		If not, OPT(i,j) = min(OPT(i,j-1),OPT(i-1,j),OPT(i-1,j-1))+1, 
//			which means insert word2[j-1] to the end of word1, delete word1[i-1] and replace word1[i-1] with word2[j-1].
//	Complexity: O(mn) in time and space, space can be optimized to O(n). m, n are the length of word1 and word2.

#include "Header.h"

using namespace std;

int minDistance(string word1, string word2)
{
	int m = word1.length(), n = word2.length();
	vector<int> pre, cur(n + 1, n);
	for (int i = 0; i <= n; i++)
	{
		pre.push_back(i);
	}
	for (int i = 1; i <= m; i++)
	{
		cur[0] = i;
		for (int j = 1; j <= n; j++)
		{
			if (word1[i - 1] == word2[j - 1])
				cur[j] = pre[j - 1];
			else
				cur[j] = min(pre[j - 1], min(pre[j], cur[j - 1])) + 1;
		}
		pre = cur;
	}
	return cur.back();
}

int main()
{
	string word1 = "oqsuqm";
	string word2 = "pamhq";
	cout << minDistance(word1, word2) << endl;
	system("pause");
	return 0;
}