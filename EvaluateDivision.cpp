//	399. Evaluate Division
//
//	Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number(floating point number).Given some queries, return the answers.If the answer does not exist, return -1.0.
//
//	Example:
//	Given a / b = 2.0, b / c = 3.0.
//	queries are : a / c = ? , b / a = ? , a / e = ? , a / a = ? , x / x = ? .
//	return[6.0, 0.5, -1.0, 1.0, -1.0].
//
//	The input is : vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries, where equations.size() == values.size(), and the values are positive.This represents the equations.Return vector<double>.
//
//	According to the example above :
//
//	equations = [["a", "b"], ["b", "c"]],
//	values = [2.0, 3.0],
//	queries = [["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]].
//
//	Written by Zhanran Tang @ 7/31/2017
//
//	Ideas: Use a map to store the equations and values, then find answer recursively.
//	Complexity: O(n^2) in time, O(n) in space. n is the size of the equations.

#include "Header.h"

using namespace std;

double divisionRecursion(unordered_map<string, unordered_map<string, double>> &divmap, string &dividend, string &divisor, unordered_set<string> &explored)
{
	if (divmap.find(dividend) == divmap.end())
		return -1;
	if (dividend == divisor)
		return 1;
	for (auto itr = divmap[dividend].begin(); itr != divmap[dividend].end(); itr++)
	{
		string second = (*itr).first;
		if (second == divisor)
			return (*itr).second;
		else
		{
			if (explored.find(second) == explored.end())
			{
				explored.insert(second);
				double res = divisionRecursion(divmap, second, divisor, explored);
				if (res != -1)
					return (*itr).second * res;
			}
		}
	}
	return -1;
}
vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries)
{
	unordered_map<string, unordered_map<string, double>> divmap;
	for (int i = 0; i<equations.size(); i++)
	{
		string dividend = equations[i].first;
		string divisor = equations[i].second;
		divmap[dividend][divisor] = values[i];
		divmap[divisor][dividend] = 1.0 / values[i];
	}
	vector<double> res;
	for (int i = 0; i<queries.size(); i++)
	{
		unordered_set<string> explored;
		string dividend = queries[i].first;
		string divisor = queries[i].second;
		res.push_back(divisionRecursion(divmap, dividend, divisor, explored));
	}
	return res;
}

int main()
{
	vector<pair<string, string>> equations = { { "x1","x2" },{ "x2","x3" },{ "x3","x4" },{ "x4","x5" } };
	vector<double> values = { 3.0,4.0,5.0,6.0 };
	vector<pair<string, string>> queries = { { "x1","x5" },{ "x5","x2" },{ "x2","x4" },{ "x2","x2" },{ "x2","x9" },{ "x9","x9" } };
	vector<double> res = calcEquation(equations, values, queries);
	cout << "[ ";
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << "]" << endl;
	system("pause");
	return 0;
}