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
    int TreeDepth(TreeNode* pRoot)
    {
        if (!pRoot)
            return 0;

        return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
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
    
    cout << s.TreeDepth(&a) << endl;
    return 0;
}