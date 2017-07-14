//	133. Clone Graph
//
//	Clone an undirected graph.Each node in the graph contains a label and a list of its neighbors.
//
//	OJ's undirected graph serialization:
//	Nodes are labeled uniquely.
//
//	We use # as a separator for each node, and, as a separator for node label and each neighbor of the node.
//	As an example, consider the serialized graph{ 0,1,2#1,2#2,2 }.
//
//	The graph has a total of three nodes, and therefore contains three parts as separated by #.
//		1. First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//		2. Second node is labeled as 1. Connect node 1 to node 2.
//		3. Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self - cycle.
//	Visually, the graph looks like the following :
//
//		1
//	   / \
//	  /   \
//	 0 --- 2
//		  / \
//		  \_/
//
//	Written by Zhanran Tang @ 7/13/2017
//
//	Ideas: DFS with a hashmap.
//	Complexity: O(m) in time. m is the number of edges. O(n) in space. n is the number of nodes.

#include "Header.h"

using namespace std;

void cloneRecursion(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*> &nodemap)
{
	nodemap.insert(pair<int, UndirectedGraphNode*>(node->label, new UndirectedGraphNode(node->label)));
	for (int i = 0; i<node->neighbors.size(); i++)
	{
		int label = node->neighbors[i]->label;
		if (nodemap.find(label) == nodemap.end())
		{
			nodemap.insert(pair<int, UndirectedGraphNode*>(label, new UndirectedGraphNode(label)));
			cloneRecursion(node->neighbors[i], nodemap);
		}
		nodemap[node->label]->neighbors.push_back(nodemap[label]);
	}
}
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	if (node == nullptr)
		return nullptr;
	unordered_map<int, UndirectedGraphNode*> nodemap;
	cloneRecursion(node, nodemap);
	return nodemap[node->label];
}

int main()
{
	UndirectedGraphNode* node0 = new UndirectedGraphNode(0);
	UndirectedGraphNode* node1 = new UndirectedGraphNode(1);
	UndirectedGraphNode* node2 = new UndirectedGraphNode(2);
	node0->neighbors.push_back(node1);
	node0->neighbors.push_back(node2);
	node1->neighbors.push_back(node0);
	node1->neighbors.push_back(node2);
	node2->neighbors.push_back(node1);
	node2->neighbors.push_back(node2);
	node2->neighbors.push_back(node0);
	UndirectedGraphNode* newgraph = cloneGraph(node0);
	system("pause");
	return 0;
}