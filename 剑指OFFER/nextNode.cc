#include <stddef.h>
#include <iostream>

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x, TreeLinkNode *p) : val(x), left(NULL), right(NULL), next(p)
    {
    }
};

class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (!pNode)
            return pNode;

        TreeLinkNode *currNode;

        if (pNode->right)
        {
            currNode = pNode->right;
            while (currNode->left)
            {
                currNode = currNode->left;
            }
            return currNode;
        }

        if (!pNode->next)
            return pNode;

        if (pNode->next->left == pNode)
            return pNode->next;

        currNode = pNode;

        while (currNode)
        {
            if (!currNode->next)
                return nullptr;

            if (currNode != currNode->next->left)
                currNode = currNode->next;
            else
                return currNode->next;
        }

        return nullptr;
    }
};

int main()
{
    struct TreeLinkNode a(1, NULL), b(2, &a), c(3, &a), d(4, &b), e(5, &b), f(6, &c), g(7, &c);

    a.left = &b;
    a.right = &c;

    b.left = &d;
    b.right = &e;

    c.left = &f;
    c.right = &g;

    Solution s;

    std::cout << s.GetNext(&g)->val << std::endl;
    return 0;
}