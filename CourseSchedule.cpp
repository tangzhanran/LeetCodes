//	207. Course Schedule
//
//	There are a total of n courses you have to take, labeled from 0 to n - 1.
//	Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
//	Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses ?
//
//	For example :
//		2, [[1, 0]]
//		There are a total of 2 courses to take.To take course 1 you should have finished course 0. So it is possible.
//
//		2, [[1, 0], [0, 1]]
//		There are a total of 2 courses to take.
//		To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
//
//	Note:
//		The input prerequisites is a graph represented by a list of edges, not adjacency matrices.Read more about how a graph is represented.
//		You may assume that there are no duplicate edges in the input prerequisites.
//
//	Written by Zhanran Tang @ 6/3/2017
//
//	Ideas: Simple BFS
//	Complexity: O(m) in time, O(m+n) in space. m is the size of prerequisites, n is numCourses

#include "Header.h"

using namespace std;

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
	if (numCourses == 0)
		return true;
	vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
	vector<int> indegree(numCourses, 0);
	queue<int> frontier;
	for (int i = 0; i<prerequisites.size(); i++)
	{
		int pre = prerequisites[i].second, after = prerequisites[i].first;
		graph[pre].insert(after);
		indegree[after]++;
	}
	for (int i = 0; i<numCourses; i++)
	{
		if (indegree[i] == 0)
			frontier.push(i);
	}
	int explored = 0;
	while (!frontier.empty())
	{
		int precourse = frontier.front();
		explored++;
		frontier.pop();
		for (auto itr = graph[precourse].begin(); itr != graph[precourse].end(); itr++)
		{
			indegree[*itr]--;
			if (indegree[*itr] == 0)
				frontier.push(*itr);
		}
	}
	if (explored == numCourses)
		return true;
	return false;
}

int main()
{
	vector<pair<int, int>> prerequisites = { pair<int,int>(1,0) };
	cout << canFinish(2, prerequisites) << endl;
	system("pause");
	return 0;
}