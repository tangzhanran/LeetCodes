//	241. Different Ways to Add Parentheses
//
//	Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators.The valid operators are + , -and *.
//
//	Example 1
//	Input: "2-1-1".
//	((2 - 1) - 1) = 0
//	(2 - (1 - 1)) = 2
//	Output : [0, 2]
//
//	Example 2
//	Input : "2*3-4*5"
//	(2 * (3 - (4 * 5))) = -34
//	((2 * 3) - (4 * 5)) = -14
//	((2 * (3 - 4)) * 5) = -10
//	(2 * ((3 - 4) * 5)) = -10
//	(((2 * 3) - 4) * 5) = 10
//	Output: [-34, -14, -10, -10, 10]
//
//	Written by Zhanran Tang @ 7/17/2017
//
//	Ideas: Break the string from operators into 2 parts, calculate the 2 parts recursively. Use map to store result.
//	Complexity: O(n) in time. Polynomial in space.

#include "Header.h"

using namespace std;

unordered_map<string, vector<int>> hashmap;
vector<int> diffWaysToCompute(string input)
{
	if (hashmap.find(input) != hashmap.end())
		return hashmap[input];
	int sz = input.length();
	if (sz <= 0)
		return vector<int>();
	vector<int> res;
	for (int i = 0; i<sz; i++)
	{
		char cur = input[i];
		if (cur == '+' || cur == '-' || cur == '*')
		{
			vector<int> leftres = diffWaysToCompute(input.substr(0, i));
			vector<int> rightres = diffWaysToCompute(input.substr(i + 1));
			for (int j = 0; j<leftres.size(); j++)
			{
				for (int k = 0; k<rightres.size(); k++)
				{
					if (cur == '+')
						res.push_back(leftres[j] + rightres[k]);
					else if (cur == '-')
						res.push_back(leftres[j] - rightres[k]);
					else
						res.push_back(leftres[j] * rightres[k]);
				}
			}
		}
	}
	if (res.empty())
		res.push_back(stoi(input));
	if (hashmap.find(input) == hashmap.end())
		hashmap[input] = res;
	return res;
}

int main()
{
	string input = "2*3-4*5";
	vector<int> res = diffWaysToCompute(input);
	cout << "[ ";
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << "]" << endl;
	system("pause");
	return 0;
}