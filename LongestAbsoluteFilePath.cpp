//	388. Longest Absolute File Path
//
//	Suppose we abstract our file system by a string in the following manner :
//
//	The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents :
//	dir
//		subdir1
//		subdir2
//			file.ext
//	The directory dir contains an empty sub - directory subdir1 and a sub - directory subdir2 containing a file file.ext.
//
//	The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
//	dir
//		subdir1
//			file1.ext
//			subsubdir1
//		subdir2
//			subsubdir2
//				file2.ext
//	The directory dir contains two sub - directories subdir1 and subdir2.subdir1 contains a file file1.ext and an empty second - level sub - directory subsubdir1.subdir2 contains a second - level sub - directory subsubdir2 containing a file file2.ext.
//
//	We are interested in finding the longest(number of characters) absolute path to a file within our file system.For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).
//
//	Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system.If there is no file in the system, return 0.
//
//	Note:
//		The name of a file contains at least a . and an extension.
//		The name of a directory or sub - directory will not contain a ..
//	Time complexity required : O(n) where n is the size of the input string.
//
//	Notice that a / aa / aaa / file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa / sth.png.
//
//	Written by Zhanran Tang @ 7/27/2017
//
//	Ideas: Store each level length in stack. P.S. It is a problem with *SUPER BAD* description.
//	Complexity: O(n) in time, O(h) in space. h is the depth of the directory tree.

#include "Header.h"

using namespace std;

int lengthLongestPath(string input)
{
	stack<int> levellength;
	levellength.push(0);
	int maxlength = 0;
	for (int i = 0; i<input.length(); i++)
	{
		int tabs = 0;
		int curlength = 0;
		bool isFile = false;
		while (input[i] == '\t')
		{
			tabs++;
			i++;
		}
		while (tabs + 1 < levellength.size())
			levellength.pop();
		while (i<input.length() && input[i] != '\n')
		{
			curlength++;
			if (input[i] == '.')
				isFile = true;
			i++;
		}
		if (isFile)
			maxlength = max(maxlength, levellength.top() + curlength);
		else
		{
			int last = levellength.top();
			levellength.push(last + curlength + 1);
		}
	}
	return maxlength;
}

int main()
{
	string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";//"dir\n        file.txt";
	cout << lengthLongestPath(input) << endl;
	system("pause");
	return 0;
}