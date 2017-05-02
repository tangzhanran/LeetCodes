//	151. Reverse Words in a String
//	Given an input string, reverse the string word by word.
//
//	For example,
//	Given s = "the sky is blue",
//	return "blue is sky the".
//
//	Written by Zhanran Tang @ 5/1/2017

#include <string>
#include <stack>
#include <iostream>

using namespace std;

void reverseWordsLinearTime(string &s)
{
	stack<string> word_stack;
	string word = "";
	for (int i = 0; i<s.length(); i++)
	{
		if (s[i] != ' ')
		{
			word += s[i];
		}
		if (i == s.length() - 1 || s[i] == ' ')
		{
			if (word != "")
				word_stack.push(word);
			word = "";
		}
	}
	s = "";
	while (!word_stack.empty())
	{
		s += word_stack.top();
		word_stack.pop();
		if (!word_stack.empty())
			s += ' ';
	}
}

void reverseWordsConstantMemory(string &s)
{
	reverse(s.begin(), s.end());
	int index = 0;
	for (int i = 0; i<s.length(); i++)
	{
		if (s[i] != ' ')
		{
			if (index != 0)
			{
				s[index] = ' ';
				index++;
			}
			int j = i;
			while (s[j] != ' ' && j<s.length())
			{
				s[index] = s[j];
				index++;
				j++;
			}
			reverse(s.begin() + index - (j - i), s.begin() + index);
			i = j;
		}
	}
	s.erase(s.begin() + index, s.end());
}

int main()
{
	string s = "the sky is blue";
	reverseWordsConstantMemory(s);
	cout << s << endl;
	system("pause");
	return 0;
}