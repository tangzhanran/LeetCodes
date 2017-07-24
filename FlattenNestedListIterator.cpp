//	341. Flatten Nested List Iterator
//
//	Given a nested list of integers, implement an iterator to flatten it.
//
//	Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//
//	Example 1:
//	Given the list[[1, 1], 2, [1, 1]],
//	By calling next repeatedly until hasNext returns false, the order of elements returned by next should be : [1, 1, 2, 1, 1].
//
//	Example 2 :
//	Given the list[1, [4, [6]]],
//	By calling next repeatedly until hasNext returns false, the order of elements returned by next should be : [1, 4, 6].
//
//	Written by Zhanran Tang @ 7/23/2017
//
//	Ideas: 
//		1. Flat the list in constructor.
//		2. Flat each NestedInteger when calling has next.
//	Complexity: Both method has polynomial time and space complexity.
//			Method 1 is better when callling hasNext many times. 
//			Method 2 is better when the list is very long and callling hasNext few times.

#include "Header.h"

using namespace	std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const { return true; };

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const { return 0; };

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const { return vector<NestedInteger>(); };

};



#define METHOD 1

#if METHOD == 1
class NestedIterator {
public:
	vector<int> m_flatList;
	int curpos;
	int listsz;
	NestedIterator(vector<NestedInteger> &nestedList)
	{
		for (int i = 0; i<nestedList.size(); i++)
		{
			flatten(nestedList[i]);
		}
		curpos = 0;
		listsz = m_flatList.size();
	}

	int next()
	{
		int nextval = 0;
		if (hasNext())
		{
			nextval = m_flatList[curpos];
			curpos++;
		}
		return nextval;
	}

	bool hasNext()
	{
		if (curpos >= listsz)
			return false;
		return true;
	}

	void flatten(NestedInteger nestedint)
	{
		if (nestedint.isInteger())
		{
			m_flatList.push_back(nestedint.getInteger());
		}
		else
		{
			vector<NestedInteger> nestlist = nestedint.getList();
			for (int i = 0; i<nestlist.size(); i++)
			{
				flatten(nestlist[i]);
			}
		}
	}
};
#elif METHOD == 2
class NestedIterator {
public:
	stack<NestedInteger> m_neststk;
	NestedIterator(vector<NestedInteger> &nestedList)
	{
		for (int i = nestedList.size() - 1; i >= 0; i--)
		{
			m_neststk.push(nestedList[i]);
		}
	}

	int next()
	{
		int nextval = 0;
		if (hasNext())
		{
			nextval = m_neststk.top().getInteger();
			m_neststk.pop();
		}
		return nextval;
	}

	bool hasNext()
	{
		while (!m_neststk.empty() && !m_neststk.top().isInteger())
		{
			vector<NestedInteger> toplist = m_neststk.top().getList();
			m_neststk.pop();
			for (int i = toplist.size() - 1; i >= 0; i--)
			{
				m_neststk.push(toplist[i]);
			}
		}
		if (!m_neststk.empty() && m_neststk.top().isInteger())
			return true;
		return false;
	}
};
#endif

int main()
{
	vector<NestedInteger> nestedList;
	NestedIterator i(nestedList);
	while (i.hasNext()) cout << i.next();
}