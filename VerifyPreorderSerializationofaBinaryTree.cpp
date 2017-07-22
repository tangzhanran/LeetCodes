//	331. Verify Preorder Serialization of a Binary Tree
//
//	One way to serialize a binary tree is to use pre - order traversal.When we encounter a non - null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
//
//		_9_
//	   /   \
//	  3     2
//	 / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
//	For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
//
//	Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree.Find an algorithm without reconstructing the tree.
//
//	Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
//
//	You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
//
//	Example 1:
//	"9,3,4,#,#,1,#,#,2,#,6,#,#"
//	Return true
//
//	Example 2 :
//	"1,#"
//	Return false
//
//	Example 3 :
//	"9,#,#,1"
//	Return false
//
//	Written by Zhanran Tang @ 7/21/2017
//
//	Ideas: 
//		1. Use a stack to track the input.
//		2. Use the difference of indegree and outdegree to track the tree.
//	Complexity: 
//		1. O(n) in time and space.
//		2. O(n) in time and O(1) in space.

#include "Header.h"

using namespace std;

#define METHOD 2

#if METHOD == 1
bool isValidSerialization(string preorder)
{
	vector<string> vec;
	string num = "";
	for (int i = 0; i<preorder.size(); i++)
	{
		if (!vec.empty() && vec[0] == "#")
			return false;
		if (preorder[i] == '#')
		{
			while (vec.size()>0 && vec.back() == "#")
			{
				vec.pop_back();
				if (vec.size() == 0)
					return false;
				vec.pop_back();
			}
			vec.push_back("#");
		}
		else if (preorder[i] == ',')
		{
			if (num != "")
			{
				vec.push_back(num);
				num = "";
			}
		}
		else
		{
			num += preorder[i];
		}
	}
	if (num != "")
		vec.push_back(num);
	if (vec.size() == 1 && vec[0] == "#")
		return true;
	return false;
}
#elif METHOD == 2
bool isValidSerialization(string preorder)
{
	if (preorder.length() == 0 || (preorder[0] == '#' && preorder.length()>1))
		return false;
	preorder += ",";
	int diff = 1;
	for (int i = 0; i<preorder.length(); i++)
	{
		if (preorder[i] == ',')
		{
			diff--;
			if (diff < 0)
				return false;
			if (preorder[i - 1] != '#')
				diff += 2;
		}
	}
	if (diff == 0)
		return true;
	return false;
}
#endif

int main()
{
	string preorder = "1,#,#,1";
	cout << isValidSerialization(preorder) << endl;
	system("pause");
	return 0;
}