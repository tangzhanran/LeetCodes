//	236. Lowest Common Ancestor of a Binary Tree
//
//	Given a binary tree, find the lowest common ancestor(LCA) of two given nodes in the tree.
//
//	According to the definition of LCA on Wikipedia : 
//	¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants(where we allow a node to be a descendant of itself).¡±
//
//		_______3_____
//		/			\
//	___5__        ___1__
//	/    \		  /	    \
//	6     2       0      8
//		 / \
//	    7   4
//	For example, the lowest common ancestor(LCA) of nodes 5 and 1 is 3. 
//	Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
//
//	Written by Zhanran Tang @ 5/29/2017
//
//	Ideas: Find p and q in left and right subtrees recursively.
//	Complexity: O(n) in time, O(1) in space

#include <cstdlib>

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == NULL || root == p || root == q)
		return root;
	TreeNode* l = lowestCommonAncestor(root->left, p, q);
	TreeNode* r = lowestCommonAncestor(root->right, p, q);
	if (l == NULL)
		return r;
	if (r == NULL)
		return l;
	return root;
}

int main()
{
	TreeNode *root = NULL, *p = NULL, *q = NULL;
	root = lowestCommonAncestor(root, p, q);
	system("pause");
	return 0;
}