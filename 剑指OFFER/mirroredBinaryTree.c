struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#include<stdlib.h>
#include<stdio.h>

/**
 * 
 * @param pRoot TreeNode类 
 * @return TreeNode类
 */
struct TreeNode* Mirror(struct TreeNode* pRoot ) {
	if (!pRoot) return NULL;

	struct TreeNode* tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;

	Mirror(pRoot->left);
	Mirror(pRoot->right);

	return pRoot;
}


int main(){
    struct TreeNode a, b, c;
    a.val = 2;
    b.val = 1;
    c.val = 3;

    a.left = &b;
    a.right = &c;

    b.left = NULL;
    b.right = NULL;

    c.left = NULL;
    c.right = NULL;


   
    printf("%i", Mirror(&a)->left->val);

    return 0;
}