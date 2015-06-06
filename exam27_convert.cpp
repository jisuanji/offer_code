#include <iostream>
using namespace std;

typedef struct BinaryTreeNode
{
	int val;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
};

class Convert
{
public:
	BinaryTreeNode * convertT(BinaryTreeNode * root)
	{
		if(root==NULL)
			return root;
		BinaryTreeNode *ret;
		BinaryTreeNode *tmp=root;
		BinaryTreeNode *lastLeft=NULL;

		while(tmp && tmp->left)
			tmp=tmp->left;
		ret=tmp;

		convertTree(root,lastLeft);
	}

	void convertTree(BinaryTreeNode * root, BinaryTreeNode * lastLeft)
	{
		if(root->left)
			convertTree(root->left, lastLeft);

		root->left=lastLeft;
		if(lastLeft)
			lastLeft->right=root;
		lastLeft=root;

		if(root->right)
			convertTree(root->right, lastLeft);
	}

};
