//	71. Simplify Path
//
//	Given an absolute path for a file(Unix - style), simplify it.
//
//	For example,
//		path = "/home/", => "/home"
//		path = "/a/./b/../../c/", => "/c"
//
//	Wirtten by Zhanran Tang @ 6/30/2017
//
//	Ideas: Using deque in STL
//	Complexity: O(n) in time and space.

#include "Header.h"

using namespace std;

string simplifyPath(string path)
{
	if (path.length() == 0 || path[0] != '/')
		return "";
	deque<string> dirstk;
	string curdir = "";
	for (int i = 0; i<path.length(); i++)
	{
		if (path[i] == '/')
		{
			while ((i + 1)<path.length() && path[i + 1] != '/')
			{
				curdir += path[i + 1];
				i++;
			}
		}
		if (curdir == "..")
		{
			if (!dirstk.empty())
				dirstk.pop_back();
		}
		else if (curdir != "." && curdir != "")
		{
			dirstk.push_back(curdir);
		}
		curdir = "";
	}
	curdir = "";
	while (!dirstk.empty())
	{
		curdir += "/";
		curdir += dirstk.front();
		dirstk.pop_front();
	}
	if (curdir == "")
		curdir = "/";
	return curdir;
}

int main()
{
	string path = "/a/./b/../../c/";
	cout << simplifyPath(path) << endl;
	system("pause");
	return 0;
}