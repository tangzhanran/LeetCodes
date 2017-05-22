//	365. Water and Jug Problem
//
//	You are given two jugs with capacities x and y litres.There is an infinite amount of water supply available.You need to determine whether it is possible to measure exactly z litres using these two jugs.
//
//	If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.
//
//	Operations allowed :
//		Fill any of the jugs completely with water.
//		Empty any of the jugs.
//		Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
//
//	Example 1 : (From the famous "Die Hard" example)
//	Input : x = 3, y = 5, z = 4
//	Output : True
//
//	Example 2 :
//	Input : x = 2, y = 6, z = 5
//	Output : False
//
//	Ideas: Rules: 
//			1. Empty the larger jug when full 
//			2. Fill the smaller jug when empty 
//			3. Pour as much water as possible from the smaller into the larger one
//	Note: Can be solve in pure math way by GCD
//	Complexity:

#include <iostream>

using namespace std;

bool canMeasureWater(int x, int y, int z)
{
	if (x == z || y == z || x + y == z)
		return true;
	if (x == 0 || y == 0)
		return false;
	if (x > y)
		swap(x, y);
	int curx = x, cury = x;
	while (true)
	{
		if (curx == z || cury == z || curx + cury == z)
			return true;
		if (curx + cury == y)
			break;
		if (curx == 0)
			curx = x;
		else if (cury == y)
			cury = 0;
		else
		{
			if (curx + cury > y)
			{
				curx = curx - y + cury;
				cury = y;
			}
			else
			{
				cury = curx + cury;
				curx = 0;
			}
		}
	}
	return false;
}

int main()
{
	int x = 3, y = 5, z = 4;
	cout << canMeasureWater(x,y,z) << endl;
	system("pause");	
	return 0;
}