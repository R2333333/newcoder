
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

void findNode(struct TreeNode* pRoot, struct TreeNode** target, int k, int* n){
    if (!pRoot)
        return;
        
    if (pRoot->left)
        findNode(pRoot->left, target, k, n);

    if ((++(*n)) == k){
        *target = pRoot;
        return;
    }

    if (pRoot->right)
        findNode(pRoot->right, target, k, n); 
}

int countNode(struct TreeNode* pRoot){
    if (!pRoot) return 0;
    return countNode(pRoot->left) + countNode(pRoot->right) + 1;
}
/**
 * 
 * @param pRoot TreeNode类 
 * @param k int整型 
 * @return TreeNode类
 */
struct TreeNode* KthNode(struct TreeNode* pRoot, int k ) {
        if(!pRoot) return 0;

        int node_count = countNode(pRoot->left);
        
        if (k <= node_count)
            return KthNode(pRoot->left, k);

        if (k == node_count + 1)
            return pRoot;
            
        return KthNode(pRoot->right, k - node_count-1);
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

   
    printf("%i", KthNode(&a, 3)->val);

    return 0;
}