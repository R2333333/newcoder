#include<stddef.h>
#include<iostream>
#include<vector>
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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (!pRoot) return true;

        vector<TreeNode*>* currLayer, *nextLayer;
        currLayer = new vector<TreeNode*>();
        nextLayer = new vector<TreeNode*>();


        currLayer->push_back(pRoot);

        while (!currLayer->empty() || !nextLayer->empty())
        {
            if (currLayer->empty()){
                delete(currLayer);
                int begin = 0,
                    end = nextLayer->size() - 1;

                for (;begin < end; begin++, end--){
                    if ((!(*nextLayer)[begin] && (*nextLayer)[end]) || ((*nextLayer)[begin] && !(*nextLayer)[end]))
                        return false;
                    if (!((*nextLayer)[begin] || (*nextLayer)[end]))
                        continue;
                    if ((*nextLayer)[begin]->val != (*nextLayer)[end]->val)
                        return false;
                }

                currLayer = nextLayer;
                nextLayer = new vector<TreeNode*>();
            }
            if (currLayer->front()){
                nextLayer->push_back(currLayer->front()->left);
                nextLayer->push_back(currLayer->front()->right);
            }

            currLayer->erase(currLayer->begin());
        }
        return true;
    }

};


int main(){
    struct TreeNode a(1), b(2), c(3), d(4), e(5), f(6), g(6);
   
    a.left = &b;
    a.right = &c;

    b.left = &d;
    b.right = &e;

    c.left = &f;
    c.right = &g;

    Solution s;

  
    std::cout << s.isSymmetrical(&a) << "\n ";
    return 0;
}