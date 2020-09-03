#include<vector>
#include<queue>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<int> ans;

        if (!root) return ans;

        nodes.push(root);

        while (!nodes.empty())
        {
            TreeNode* currNode = nodes.front();
            nodes.pop();

            if (!currNode) continue;

            ans.push_back(currNode->val);

            nodes.push(currNode->left);
            nodes.push(currNode->right);
        }

        return ans;
    }
};


int main(){
    struct TreeNode a(1), b(2), c(3), d(4), e(5), f(6), g(7);
   
    a.left = &b;
    a.right = &c;

    b.left = &d;
    b.right = &e;

    c.left = &f;
    c.right = &g;

    Solution s;

  
    vector<int> v = s.PrintFromTopToBottom(&a);
    for (vector<int>::iterator it = v.begin(); *it; ++it){
        cout << *it << " ";
    }
    cout << "\n ";
    return 0;
}