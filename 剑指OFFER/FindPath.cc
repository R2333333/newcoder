#include <stddef.h>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    vector<vector<int> > FindPath(TreeNode *root, int expectNumber)
    {
        vector<int> path;
        vector<vector<int> > ans;

        if (!root)
            return ans;

        findPath(root, expectNumber, &path, &ans);

        return ans;
    }

    void findPath(TreeNode *node, int num, vector<int> *path, vector<vector<int> > *ans)
    {

        path->push_back(node->val);

        if (num == node->val && !node->left && !node->right)
        {
            ans->push_back(*path);
        }

        if (node->left)
            findPath(node->left, num - node->val, path, ans);
        if (node->right)
            findPath(node->right, num - node->val, path, ans);

        path->pop_back();
    }
};

int main()
{
    struct TreeNode a(1), b(2), c(3), d(4), e(5), f(6), g(7), h(-1);

    a.left = &b;
    a.right = &c;

    b.left = &d;
    b.right = &e;

    c.left = &f;
    c.right = &g;

    e.right = &h;

    Solution s;

    vector<vector<int> > v = s.FindPath(&a, 7);
    for (vector<vector<int> >::iterator it = v.begin(); it != v.end(); ++it)
    {
        for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
        {
            cout << *it2 << " ";
        }

        cout << "\n";
    }
    return 0;
}