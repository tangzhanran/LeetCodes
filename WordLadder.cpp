//	127. Word Ladder
//
//	Given two words(beginWord and endWord), and a dictionary's word list, 
//	find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//	1. Only one letter can be changed at a time.
//	2. Each transformed word must exist in the word list.Note that beginWord is not a transformed word.
//	For example,
//
//	Given:
//	beginWord = "hit"
//	endWord = "cog"
//	wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
//	As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//	return its length 5.
//
//	Note :
//		Return 0 if there is no such transformation sequence.
//		All words have the same length.
//		All words contain only lowercase alphabetic characters.
//		You may assume no duplicates in the word list.
//		You may assume beginWord and endWord are non - empty and are not the same.
//
//	Written by Zhanran Tang @ 5/3/2017 Time Exceed for some samples
//	
//	Idea: Tree with BFS

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

bool compareWord(string str1, string str2)
{
	int count = 0;
	for (int i = 0; i<str1.length(); i++)
	{
		if (str1[i] != str2[i])
			count++;
		if (count > 1)
			return false;
	}
	if (count == 0)
		return false;
	return true;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	int step = 1, current_level = 1, next_level = 0;
	unordered_set<string> visited_set;
	queue<string> frontier;
	frontier.push(beginWord);
	visited_set.insert(beginWord);

	while (!frontier.empty())
	{
		string front = frontier.front();
		frontier.pop();
		for (int i = 0; i<wordList.size(); i++)
		{
			if (visited_set.find(wordList[i]) == visited_set.end())
			{
				if (compareWord(front, wordList[i]))
				{
					if (wordList[i] == endWord)
						return step + 1;
					frontier.push(wordList[i]);
					visited_set.insert(wordList[i]);
					next_level++;
				}
			}
		}
		current_level--;
		if (current_level == 0)
		{
			step++;
			current_level = next_level;
			next_level = 0;
		}
	}
	return 0;
}

int main()
{
	return 0;
}