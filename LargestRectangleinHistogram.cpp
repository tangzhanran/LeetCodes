//	84. Largest Rectangle in Histogram
//
//	Given n non - negative integers representing the histogram's bar height where the width of each bar is 1, 
//	find the area of largest rectangle in the histogram.
//
//	Above is a histogram where width of each bar is 1, given height = [2, 1, 5, 6, 2, 3].
//
//	The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//	For example,
//	Given heights = [2, 1, 5, 6, 2, 3],
//	return 10.
//
//	Written by Zhanran Tang @ 9/6/2017
//
//	Ideas: Using a stack to store index whose height is in a increasing sequence. 
//		While the top height in the stack is greater or equal to height[i]:
//			record the height at the top of the stack and pop. 
//			If there are no element in stack, the width should be i.
//			If there are still element in stack, the width should be i-1-new top index.
//		Push i into stack.
//	Complexity: O(n) in space and time.

#include "Header.h"

using namespace std;

int largestRectangleArea(vector<int>& heights)
{
	heights.push_back(0);
	stack<int> indexstk;
	int maxarea = 0;
	for (int i = 0; i<heights.size(); i++)
	{
		while (!indexstk.empty() && heights[indexstk.top()] >= heights[i])
		{
			int curh = heights[indexstk.top()];
			indexstk.pop();
			if (indexstk.empty())
				maxarea = max(maxarea, curh*i);
			else
				maxarea = max(maxarea, curh*(i - indexstk.top() - 1));
		}
		indexstk.push(i);
	}
	return maxarea;
}

int main()
{
	vector<int> heights = { 2,1,5,6,2,3 };
	cout << largestRectangleArea(heights) << endl;
	system("pause");
	return 0;
}