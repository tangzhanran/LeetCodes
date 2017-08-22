//	417. Pacific Atlantic Water Flow
//
//	Given an m x n matrix of non - negative integers representing the height of each unit cell in a continent, 
//	the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
//
//	Water can only flow in four directions(up, down, left, or right) from a cell to another one with height equal or lower.
//
//	Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
//
//	Note:
//		1. The order of returned grid coordinates does not matter.
//		2. Both m and n are less than 150.
//
//	Example :
//	Given the following 5x5 matrix :
//	Pacific ~~~~~
//	~1   2   2   3  (5) *
//	~3   2   3  (4) (4) *
//	~2   4  (5)  3   1 *
//	~(6) (7)  1   4   5 *
//	~(5)  1   1   2   4 *
//	  *   *   *   *   * Atlantic
//
//	Return :
//	[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]](positions with parentheses in above matrix).
//
//	Ideas: Using BFS to find 2 sets of position for Pacific and Atlantic respectively, then find the duplicate.
//	Complexity: O(mn) in time and space.

#include "Header.h"

using namespace std;

void BFS(queue<int> &q, unordered_set<int> &s, vector<vector<int>>& matrix, int m, int n)
{
	while (!q.empty())
	{
		int x = q.front() / n;
		int y = q.front() % n;
		q.pop();
		if (x>0 && s.find((x - 1)*n + y) == s.end() && matrix[x - 1][y] >= matrix[x][y])
		{
			q.push((x - 1)*n + y);
			s.insert((x - 1)*n + y);
		}
		if (x + 1<m && s.find((x + 1)*n + y) == s.end() && matrix[x + 1][y] >= matrix[x][y])
		{
			q.push((x + 1)*n + y);
			s.insert((x + 1)*n + y);
		}
		if (y + 1<n && s.find(x*n + y + 1) == s.end() && matrix[x][y + 1] >= matrix[x][y])
		{
			q.push(x*n + y + 1);
			s.insert(x*n + y + 1);
		}
		if (y>0 && s.find(x*n + y - 1) == s.end() && matrix[x][y - 1] >= matrix[x][y])
		{
			q.push(x*n + y - 1);
			s.insert(x*n + y - 1);
		}
	}
}
vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix)
{
	int m = matrix.size(), n = 0;
	if (m > 0)
		n = matrix[0].size();
	queue<int> pq, aq;
	unordered_set<int> ps, as;
	vector<pair<int, int>> res;
	for (int i = 0; i<m; i++)
	{
		pq.push(i*n);
		aq.push(i*n + n - 1);
		ps.insert(i*n);
		as.insert(i*n + n - 1);
	}
	for (int j = 0; j<n; j++)
	{
		pq.push(j);
		aq.push((m - 1)*n + j);
		ps.insert(j);
		as.insert((m - 1)*n + j);
	}
	BFS(pq, ps, matrix, m, n);
	BFS(aq, as, matrix, m, n);
	for (auto itr = ps.begin(); itr != ps.end(); itr++)
	{
		int val = *itr;
		if (as.find(val) != as.end())
			res.push_back(pair<int, int>(val / n, val%n));
	}
	return res;
}

int main()
{
	vector<vector<int>> matrix = { { 1,2,2,3,5 },{ 3,2,3,4,4 },{ 2,4,5,3,1 },{ 6,7,1,4,5 },{ 5,1,1,2,4 } };
	vector<pair<int, int>> res = pacificAtlantic(matrix);
	for (int i = 0; i < res.size(); i++)
		cout << "[" << res[i].first << "," << res[i].second << "]" << endl;
	system("pause");
	return 0;
}