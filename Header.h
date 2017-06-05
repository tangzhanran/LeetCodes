#ifndef HEADER_H_
#define HEADER_H_

//	head files

//oslibs
#include <cstdlib>

//stl data structures
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

//iostreams
#include <iostream>

// custom structures
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif // !HEADER_H_
#pragma once
