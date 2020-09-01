#include<stddef.h>
#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!(pRoot1 && pRoot2)) return false;
        return hasSubTree(pRoot1, pRoot2) 
            || hasSubTree(pRoot1->left, pRoot2)
            || hasSubTree(pRoot1->right, pRoot2);
    }
    
    bool hasSubTree(TreeNode* pRoot1, TreeNode* pRoot2){
        if (!pRoot2) return true;
        if (!pRoot1) return false;

        return (pRoot1->val == pRoot2->val)
            && hasSubTree(pRoot1->left, pRoot2->left)
            && hasSubTree(pRoot1->right, pRoot2->right);
    } 
};


int main(){
    struct TreeNode a(8), b(8), c(7), d(9), e(2), f('#'), g('#'), h('#'), i('#'),
        j(4), k(7), l(8), m(9), n(2);
   
    a.left = &b;
    a.right = &c;

    b.left = &d;
    b.right = &e;

    c.left = &f;
    c.right = &g;

    d.left = &h;
    d.right = &i;

    e.left = &j;
    e.right = &k;

    l.left = &m;
    l.right = &n;

    Solution s;
    
    cout << s.HasSubtree(&a, &l);
    return 0;
}