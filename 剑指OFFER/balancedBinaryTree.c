#include<stdbool.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int height(struct TreeNode* pRoot){
    if (!pRoot) return 0;
    int l = height(pRoot->left), r = height(pRoot->right);
    return (l > r ? l : r) + 1;
}


/**
 * 
 * @param pRoot TreeNode类 
 * @return bool布尔型
 */
bool IsBalanced_Solution(struct TreeNode* pRoot) {
    if (!pRoot) return true;

    if (abs(height(pRoot->left) - height(pRoot->right)) > 1)
        return false;

    return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}

