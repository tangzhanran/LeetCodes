//	211. Add and Search Word - Data structure design
//
//	Design a data structure that supports the following two operations :
//
//	void addWord(word)
//	bool search(word)
//	search(word) can search a literal word or a regular expression string containing only letters a - z or ..A.means it can represent any one letter.
//
//	For example :
//
//	addWord("bad")
//	addWord("dad")
//	addWord("mad")
//	search("pad") -> false
//	search("bad") -> true
//	search(".ad") -> true
//	search("b..") -> true
//
//	Written by Zhanran Tang @5/7/2017	Wrong Answer at 12/13
//	
//	Idea:	TrieTree

#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

struct TrieNode
{
	char val;
	bool isEnd;
	//int shareNum;
	vector<TrieNode*> children;
	TrieNode(char v, bool end) : val(v), isEnd(end) {}
};

class WordDictionary
{
private:
	TrieNode *root;
public:
	/** Initialize your data structure here. */
	WordDictionary()
	{
		root = new TrieNode('*', false);
	}

	/** Adds a word into the data structure. */
	void addWord(string word)
	{
		if (search(word))
			return;
		TrieNode *cur = root, *next = NULL;
		for (int i = 0; i<word.length(); i++)
		{
			next = searchDepthLetter(cur, word[i], 0);
			if (next == NULL)
			{
				bool end = false;
				if (i == word.length() - 1)
					end = true;
				TrieNode* newNode = new TrieNode(word[i], end);
				cur->children.push_back(newNode);
				cur = newNode;
			}
			else
				cur = next;
		}
		cur->isEnd = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word)
	{
		TrieNode *cur = root;
		int i = 0, l = word.length(), depth = 0;
		char curchar;
		while (i < l)
		{
			depth = 0;
			curchar = word[i];
			while (curchar == '.')
			{
				i++;								
				if (i == l)
					break;
				curchar = word[i];
				depth++;
			}
			cur = searchDepthLetter(cur, curchar, depth);
			if (cur == NULL)
				return false;
			i++;
		}
		return cur->isEnd;
	}

	TrieNode* searchDepthLetter(TrieNode *head, char letter, int depth)
	{
		if (head == NULL)
			return head;
		TrieNode* child = NULL;
		for (int i = 0; i<head->children.size(); i++)
		{
			if (depth > 0)
			{
				child = searchDepthLetter(head->children[i], letter, depth - 1);
				if (child != NULL)
					return child;
			}
			else
			{
				if (letter == '.' || head->children[i]->val == letter)
					return head->children[i];
			}
		}
		return child;
	}
};

int main()
{
	WordDictionary obj = WordDictionary();
	obj.addWord("unpass");
	obj.addWord("passionate");
	obj.addWord("forepassed");
	obj.addWord("overpassionateness");
	obj.addWord("passionateness");
	cout << obj.search("..pass") << endl;
	system("pause");
	return 0;
}