#include <iostream>
using namespace std;

typedef struct BitreeNode
{
	int val;
	BitreeNode * left;
	BitreeNode * right;
};

bool isBalancedTree(BitreeNode * root, int & depth)
{
	if(root==NULL)
	{
		depth=0;
		return true;
	}
	else
	{
		int left, right;
		if(isBalancedTree(root->left, left) || isBalancedTree(root->right, right))
		{
			if(left-right>1 || right-left>1)
				return false;
			else
			{
				depth=1+(left>right?left:right);
				return true;;
			}
		}
		
		return false;
	}
}

//void main()
//{
//
//}