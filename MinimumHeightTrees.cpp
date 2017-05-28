//	310. Minimum Height Trees
//
//	For a undirected graph with tree characteristics, we can choose any node as the root.
//	The result graph is then a rooted tree.
//	Among all possible rooted trees, those with minimum height are called minimum height trees(MHTs).
//	Given such a graph, write a function to find all the MHTs and return a list of their root labels.
//
//	Format
//	The graph contains n nodes which are labeled from 0 to n - 1. 
//	You will be given the number n and a list of undirected edges(each edge is a pair of labels).
//
//	You can assume that no duplicate edges will appear in edges.
//	Since all edges are undirected, [0, 1] is the same as[1, 0] and thus will not appear together in edges.
//
//	Example 1:
//	Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
//	0
//	|
//	1
//	/ \
//	2   3
//	return[1]
//
//	Example 2:
//	Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
//	0  1  2
//	\ | /
//	3
//	|
//	4
//	|
//	5
//	return[3, 4]
//
//	Note:
//	(1) According to the definition of tree on Wikipedia : ¡°a tree is an undirected graph in which any two vertices are connected by exactly one path.In other words, any connected graph without simple cycles is a tree.¡±
//	(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
//
//	Written by Zhanran Tang @ 5/26/2017
//
//	Ideas: 1. Simple DFS rooted at each node. Compare the depth. 
//		2. Delete leaves nodes iteratively. Stop when less or equal to 2 nodes left
//	Complexity: 1. O(n*m^2) in time, O(n) in space. 2. O(n+2m) in time and space

#include <vector>
#include <cstdlib>
#include <unordered_set>
#include <iostream>

#define SAVETIME 1

using namespace std;

#if !SAVETIME
struct myListNode
{
	int val;
	vector<myListNode*> children;
	myListNode(int v) : val(v), children(NULL) {}
};

int calDepth(myListNode* root, unordered_set<int> explored)
{
	if (root == NULL)
		return 0;
	int maxdepth = 1;
	for (int i = 0; i<root->children.size(); i++)
	{
		if (explored.find(root->children[i]->val) != explored.end())
			continue;
		explored.insert(root->children[i]->val);
		int childdepth = calDepth(root->children[i], explored) + 1;
		if (childdepth > maxdepth)
			maxdepth = childdepth;
	}
	return maxdepth;
}
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
{
	vector<myListNode*> nodes;
	for (int i = 0; i<n; i++)
		nodes.push_back(new myListNode(i));
	for (int i = 0; i<edges.size(); i++)
	{
		nodes[edges[i].first]->children.push_back(nodes[edges[i].second]);
		nodes[edges[i].second]->children.push_back(nodes[edges[i].first]);
	}
	vector<int> res;
	int min = n;
	for (int i = 0; i<n; i++)
	{
		unordered_set<int> explored;
		explored.insert(nodes[i]->val);
		int depth = calDepth(nodes[i], explored);
		if (depth < min)
		{
			res = vector<int>();
			res.push_back(i);
			min = depth;
		}
		else if (depth == min)
			res.push_back(i);
	}
	return res;
}
#else
struct myListNode
{
	int val;
	unordered_set<int> neighbours;
	myListNode(int v) : val(v) {}
};
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
{
	vector<myListNode> nodes;
	unordered_set<int> nodenums;
	for (int i = 0; i<n; i++)
	{
		nodes.push_back(myListNode(i));
		nodenums.insert(i);
	}
	for (int i = 0; i<edges.size(); i++)
	{
		nodes[edges[i].first].neighbours.insert(edges[i].second);
		nodes[edges[i].second].neighbours.insert(edges[i].first);
	}
	vector<int> leaves;
	for (int i = 0; i<n; i++)
	{
		if (nodes[i].neighbours.size() == 1)
			leaves.push_back(nodes[i].val);
	}
	vector<int> nextleaves;
	while (nodenums.size() > 2)
	{
		for (int i = 0; i<leaves.size(); i++)
		{
			nodenums.erase(leaves[i]);
			for (auto itr = nodes[leaves[i]].neighbours.begin(); itr != nodes[leaves[i]].neighbours.end(); itr++)
			{
				nodes[*itr].neighbours.erase(leaves[i]);
				if (nodes[*itr].neighbours.size() == 1)
					nextleaves.push_back(*itr);
			}			
		}
		leaves = nextleaves;
		nextleaves.clear();
	}
	vector<int> res;
	for (auto i = nodenums.begin(); i != nodenums.end(); i++)
		res.push_back(*i);
	return res;
}
#endif

int main()
{
	int n = 6;
	vector<pair<int, int>> edges = { {0,3},{1,3},{2,3},{ 4,3 },{ 5,4 } };
	vector<int> res = findMinHeightTrees(n, edges);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}