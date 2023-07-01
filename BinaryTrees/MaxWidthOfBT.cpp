// Problem:
// Given the root of a binary tree, return the maximum width of the given tree.
// The maximum width of a tree is the maximum width among all levels.
// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// APPROACH:
// 1. Level order traversal will be used since we have to count no. of nodes at each level.
// 2. The idea is to give index to each node (considering index of intermediate NULL nodes too) starting from root as 0 so that we can easily find no. of nodes at each level by (rightIndex-leftIndex + 1)
// 3. For a node having index i, index of left child = 2*i+1 and index of right child = 2*i+2

int widthOfBinaryTree(TreeNode *root)
{
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0}); // {node, index}

    int ans = 0;

    while (!q.empty())
    {
        int size = q.size();
        int firstIdx = q.front().second;
        int lastIdx = q.back().second;
        ans = max(ans, lastIdx - firstIdx + 1);

        for (int i = 0; i < size; i++)
        {
            int idx = q.front().second - firstIdx; // modified index to avoid OVERFLOW in case of skewed trees
            TreeNode *node = q.front().first;
            q.pop();

            if (node->left != NULL)
            {
                q.push({node->left, (long long)2 * idx + 1});
            }

            if (node->right != NULL)
            {
                q.push({node->right, (long long)2 * idx + 2});
            }
        }
    }

    return ans;
}

int main()
{
    return 0;
}