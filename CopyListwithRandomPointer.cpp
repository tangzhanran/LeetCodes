//	138. Copy List with Random Pointer
//
//	A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//	Return a deep copy of the list.
//
//	Written by Zhanran Tang @ 5/18/2017
//
//	Ideas:	Using a Hash Map to do recursively.
//	Complexity:	O(n) in time. O(n) in space. n-length of the link list
//	Note: Can be done in O(n) time and O(1) space.

#include <cstdlib>
#include <unordered_map>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

unordered_map<int, RandomListNode*> explored;

RandomListNode *copyRandomList(RandomListNode *head)
{
	if (head == NULL)
		return NULL;
	if (explored.find(head->label) != explored.end())
		return explored[head->label];
	RandomListNode *newhead = new RandomListNode(head->label);
	explored[head->label] = newhead;
	newhead->next = copyRandomList(head->next);
	newhead->random = copyRandomList(head->random);
	return newhead;
}

int main()
{
	RandomListNode *list = NULL;
	RandomListNode *copy = copyRandomList(list);
	system("pause");
	return 0;
}