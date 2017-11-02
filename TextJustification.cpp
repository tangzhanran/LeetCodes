//	68. Text Justification
//
//	Given an array of words and a length L, format the text such that each line has exactly L characters and is fully(left and right) justified.
//
//	You should pack your words in a greedy approach; that is, pack as many words as you can in each line.Pad extra spaces ' ' when necessary so that each line has exactly L characters.
//
//	Extra spaces between words should be distributed as evenly as possible.If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//
//	For the last line of text, it should be left justified and no extra space is inserted between words.
//
//	For example,
//	words: ["This", "is", "an", "example", "of", "text", "justification."]
//		L : 16.
//
//		Return the formatted lines as :
//	[
//		"This    is    an",
//		"example  of text",
//		"justification.  "
//	]	
//	Note : Each word is guaranteed not to exceed L in length.
//
//	Written by Zhanran Tang @ 10/20/2017
//
//	Ideas: seperate words into rows, then add space.
//	Complexity: O(n) in time and space.

#include "Header.h"

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth)
{
	vector<string> res;
	vector<pair<int, int>> rowcount; //store row end index and word length
	rowcount.push_back(pair<int, int>(0, 0));
	int curlen = 0, lenwspace = 0;
	for (int i = 0; i<words.size(); i++)
	{
		if (lenwspace + words[i].length() <= maxWidth)
		{
			curlen += words[i].length();
			lenwspace += words[i].length();
			if (lenwspace < maxWidth)
				lenwspace += 1;
		}
		else
		{
			rowcount.push_back(pair<int, int>(i, curlen));
			curlen = words[i].length();
			lenwspace = words[i].length() + 1;
		}
	}
	rowcount.push_back(pair<int, int>(words.size(), curlen));
	int n = rowcount.size();
	for (int i = 1; i<n - 1; i++)
	{
		int start = rowcount[i - 1].first, end = rowcount[i].first;
		int count = end - start;
		int len = rowcount[i].second;
		int avgspace = (maxWidth - len) / count;
		int mod = (maxWidth - len) % count;
		if (count > 1)
		{
			avgspace = (maxWidth - len) / (count - 1);
			mod = (maxWidth - len) % (count - 1);
		}
		string str = "";
		string spaces(avgspace, ' ');
		while (start < end)
		{
			str += words[start];
			if (start < end - 1 || count == 1)
			{
				str += spaces;
				if (mod > 0)
				{
					str += " ";
					mod--;
				}
			}
			start++;
		}
		res.push_back(str);
	}
	string tmpstr = "";
	for (int i = rowcount[n - 2].first; i<rowcount[n - 1].first; i++)
	{
		tmpstr += words[i];
		if (i != rowcount[n - 1].first - 1)
			tmpstr += " ";
	}
	string sp(maxWidth - tmpstr.length(), ' ');
	tmpstr += sp;
	res.push_back(tmpstr);
	return res;
}