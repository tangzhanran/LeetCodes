//	210. Course Schedule II
//
//	There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//	Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
//
//	Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
//
//	There may be multiple correct orders, you just need to return one of them.If it is impossible to finish all courses, return an empty array.
//
//	For example :
//
//	2, [[1, 0]]
//	There are a total of 2 courses to take.To take course 1 you should have finished course 0. So the correct course order is[0, 1]
//
//	4, [[1, 0], [2, 0], [3, 1], [3, 2]]
//	There are a total of 4 courses to take.To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is[0, 1, 2, 3].Another correct ordering is[0, 2, 1, 3].
//
//	Note:
//		The input prerequisites is a graph represented by a list of edges, not adjacency matrices.Read more about how a graph is represented.
//		You may assume that there are no duplicate edges in the input prerequisites.
//
//	Written by Zhanran Tang @ 5/21/2017
//
//	Ideas: Simple BFS on Directed Graph
//	Complexity: O(n^2) in time, O(n) in space. n - the number of course


#include <vector>
#include <queue>

using namespace std;

struct CourseNode
{
	int course;
	int indegree;
	vector<CourseNode*> children;
	CourseNode(int c, int d) : course(c), indegree(d) {}
};

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
	vector<CourseNode*> coursevec;
	for (int i = 0; i<numCourses; i++)
		coursevec.push_back(new CourseNode(i, 0));
	for (int i = 0; i<prerequisites.size(); i++)
	{
		coursevec[prerequisites[i].second]->children.push_back(coursevec[prerequisites[i].first]);
		coursevec[prerequisites[i].first]->indegree++;
	}
	queue<CourseNode*> noparents;
	for (int i = 0; i<numCourses; i++)
	{
		if (coursevec[i]->indegree == 0)
			noparents.push(coursevec[i]);
	}
	vector<int> res;
	while (res.size() < numCourses)
	{
		if (noparents.empty())
			return vector<int>();
		CourseNode *cur = noparents.front();
		noparents.pop();
		res.push_back(cur->course);
		for (int i = 0; i<cur->children.size(); i++)
		{
			cur->children[i]->indegree--;
			if (cur->children[i]->indegree == 0)
				noparents.push(cur->children[i]);
		}
	}
	return res;
}

int main()
{
	int n = 2;
	vector<pair<int, int>> pre;
	pre.push_back(pair<int, int>(1, 0));
	pre.push_back(pair<int, int>(0, 1));
	vector<int> res = findOrder(n, pre);
	system("pause");
	return 0;
}