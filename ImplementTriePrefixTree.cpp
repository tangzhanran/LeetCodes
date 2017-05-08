//	208. Implement Trie(Prefix Tree)
//
//	Implement a trie with insert, search, and startsWith methods.
//
//	Note:
//	You may assume that all inputs are consist of lowercase letters a - z.
//
//	Written by Zhanran Tang @ 5/6/2017
//
//	Idea: Trie Tree

#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

struct TrieNode
{
	char val;
	bool isEnd;
	int shareNum;
	vector<TrieNode*> children;
	TrieNode(char v, bool end, int share) : val(v), isEnd(end), shareNum(share) {}
};

class Trie {
private:
	TrieNode *root;
public:
	/** Initialize your data structure here. */
	Trie()
	{
		root = new TrieNode('*', false, 0);
	}

	/** Inserts a word into the trie. */
	void insert(string word)
	{
		if (search(word))
			return;
		TrieNode *current = root, *tmp = root;
		for (int i = 0; i<word.length(); i++)
		{
			tmp = findLetterNode(current, word[i]);
			if (tmp == NULL)
			{
				bool end = false;
				if (i == word.length() - 1)
					end = true;
				TrieNode* newNode = new TrieNode(word[i], end, 0);
				current->children.push_back(newNode);
				current = newNode;
			}
			else
			{
				current = tmp;
			}
			current->shareNum++;
		}
		current->isEnd = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		TrieNode *current = root;
		for (int i = 0; i<word.length(); i++)
		{
			current = findLetterNode(current, word[i]);
			if (current == NULL)
				return false;
		}
		return current->isEnd;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix)
	{
		TrieNode *current = root;
		for (int i = 0; i<prefix.length(); i++)
		{
			current = findLetterNode(current, prefix[i]);
			if (current == NULL)
				return false;
		}
		return true;
	}

	TrieNode* findLetterNode(TrieNode* head, char letter)
	{
		if (head == NULL)
			return head;
		for (int i = 0; i<head->children.size(); i++)
		{
			if (head->children[i]->val == letter)
				return head->children[i];
		}
		return NULL;
	}
};

int main()
{
	Trie obj = Trie();
	obj.insert("add");
	cout << obj.search("ad") << endl;
	obj.startsWith("a");
	system("pause");
	return 0;
}