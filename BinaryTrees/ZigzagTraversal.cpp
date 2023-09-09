// Problem:
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// APPROACH: This problem is an extended version of Level order traversal
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    vector<int> temp;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;

// --------------------- M1: By reversing the temp vector -----------------------
// while (!q.empty())
// {
//     int n = q.size();

//     for (int i = 0; i < n; i++)
//     {
//         TreeNode *node = q.front();
//         q.pop();
//         temp.push_back(node->val);
//         if (node->left != NULL)
//         {
//             q.push(node->left);
//         }
//         if (node->right != NULL)
//         {
//             q.push(node->right);
//         }
//     }
//     if (level % 2 != 0)
//     {
//         reverse(temp.begin(), temp.end());
//     }
//     ans.push_back(temp);
//     level++;
//     temp.clear();
// }

// return ans;

    //  -------------------- M2: Without reversing temp vector ---------------------------
    bool leftToRight = true;

    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            // find position to fill current node value
            int index = (leftToRight) ? i : (n - 1 - i);
            temp[index] = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ans.push_back(temp);
        // for next level level
        leftToRight = !leftToRight;
    }
}

int main()
{
    return 0;
}