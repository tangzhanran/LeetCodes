//	134. Gas Station
//
//	There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//
//	You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station(i + 1).You begin the journey with an empty tank at one of the gas stations.
//
//	Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
//
//	Note:
//	The solution is guaranteed to be unique.
//
//	Written by Zhanran Tang @ 5/27/22017
//
//	Ideas: When stuck, start pos jump to next. Record the insufficient gas.
//	Complexity: O(n) in time, O(1) in space.

#include <vector>
#include <iostream>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	int n = gas.size();
	int totalcost = 0, totalgas = 0, insufficient = 0;
	int start = 0, i = 0;
	while (i < n)
	{
		totalcost += cost[i];
		totalgas += gas[i];
		if (totalgas < totalcost)
		{
			insufficient += totalcost - totalgas;
			start = i + 1;
			totalcost = 0;
			totalgas = 0;
		}
		i++;
	}
	if (insufficient <= totalgas - totalcost)
		return start;
	else
		return -1;
}

int main()
{
	vector<int> gas = { 1, 2, 3, 4, 5 };
	vector<int> cost = { 3,4,5,1,2 };
	cout << canCompleteCircuit(gas, cost) << endl;
	system("pause");
	return 0;
}