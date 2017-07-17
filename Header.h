#ifndef HEADER_H_
#define HEADER_H_

//	head files

//oslibs
#include <cstdlib>

//stl headers
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <deque>
#include <functional>

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

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeLinkNode 
{
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
};

struct UndirectedGraphNode 
{
	int label;
	std::vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

#endif // !HEADER_H_
#pragma once
