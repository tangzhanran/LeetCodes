//	385. Mini Parser
//
//	Given a nested list of integers represented as a string, implement a parser to deserialize it.
//
//	Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//
//	Note: You may assume that the string is well - formed :
//		1. String is non - empty.
//		2. String does not contain white spaces.
//		3. String contains only digits 0 - 9, [, -, , ].
//
//	Example 1 :
//	Given s = "324",
//	You should return a NestedInteger object which contains a single integer 324.
//
//	Example 2 :
//	Given s = "[123,[456,[789]]]",
//	Return a NestedInteger object containing a nested list with 2 elements :
//		1. An integer containing value 123.
//		2. A nested list containing two elements :
//			i.An integer containing value 456.
//			ii.A nested list with one element :
//				a.An integer containing value 789.
//
//	Written by Zhanran Tang @ 5/31/2017
//
//	Ideas: 1. Split the string into segments and parse recursively
//	Complexity: 1. O(n^2) in time, O(n) in space

#include <vector>
#include <string>

using namespace std;

class NestedInteger {
	public:
		// Constructor initializes an empty nested list.
		NestedInteger();
		
		// Constructor initializes a single integer.
		NestedInteger(int value);

		// Return true if this NestedInteger holds a single integer, rather than a nested list.
		bool isInteger() const;
		
		// Return the single integer that this NestedInteger holds, if it holds a single integer
		// The result is undefined if this NestedInteger holds a nested list
		int getInteger() const;
		
		// Set this NestedInteger to hold a single integer.
		void setInteger(int value);
	
		// Set this NestedInteger to hold a nested list and adds a nested integer to it.
		void add(const NestedInteger &ni);
		
		// Return the nested list that this NestedInteger holds, if it holds a nested list
		// The result is undefined if this NestedInteger holds a single integer
		const vector<NestedInteger> &getList() const;
};

int string2int(string s)
{
	int res = 0, sign = 1, begin = 0;
	if (s[0] == '-')
	{
		sign = -1;
		begin = 1;
	}
	for (int i = begin; i<s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res * 10 + s[i] - 48;
	}
	return sign * res;
}
vector<string> findSegment(string str)
{
	vector<string> segments;
	if (str == "")
		return segments;
	string seg = "";
	int sbcnt = 0;
	for (int i = 0; i<str.size(); i++)
	{
		if (str[i] == ',' && sbcnt == 0)
		{
			segments.push_back(seg);
			seg = "";
		}
		else
		{
			if (str[i] == '[')
				sbcnt++;
			else if (str[i] == ']')
				sbcnt--;
			seg += str[i];
		}
	}
	segments.push_back(seg);
	return segments;
}
NestedInteger recursiveParse(string str)
{
	NestedInteger val;
	vector<string> segments;
	if (str[0] != '[')
	{
		segments = findSegment(str);
		if (segments.empty())
			return val;
		val.setInteger(string2int(segments[0]));
		return val;
	}
	else
		segments = findSegment(str.substr(1, str.length() - 2));
	for (int i = 0; i<segments.size(); i++)
	{
		val.add(recursiveParse(segments[i]));
	}
	return val;
}
NestedInteger deserialize(string s)
{
	if (s == "")
		return NestedInteger();
	return recursiveParse(s);
}

int main()
{
	NestedInteger res;
	system("pause");
	return 0;
}
