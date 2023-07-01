// PROBLEM:
// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// ***************** M1: Using unordered_set ***************
bool dfs(Node *root, unordered_set<int> &s, int &k)
{
    if (root == NULL)
        return false;
    if (s.count(k - root->val))
    {
        return true;
    }

    s.insert(root->val);
    return dfs(root->left, s, k) || dfs(root->right, s, k);
}
bool findTarget(Node *root, int k)
{
    unordered_set<int> s;
    return dfs(root, s, k);
}

// *************** M2: Using Inorder traversal & two pointer **************

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}
bool findTarget(Node *root, int k)
{
    vector<int> v;
    inorder(root, v);

    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        int sum = v[i] + v[j];
        if (sum == k)
        {
            return true;
        }
        else if (sum < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return false;
}

// ******************** M3: Using BST Iterator **************

class BSTIterator
{
    stack<Node *> s;
    bool reverse = true;
    void pushAll(Node *root)
    {
        while (root != NULL)
        {
            s.push(root);
            if (reverse)
            {
                // Go to extreme right
                root = root->right;
            }
            else
            {
                // Go to extreme left
                root = root->left;
            }
        }
    }

public:
    BSTIterator(Node *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        Node *top = s.top();
        s.pop();

        if (reverse)
        {
            // if reverse==true, acts as before()
            // before stores all the elements in descending order
            pushAll(top->left);
        }
        else
        {
            // else acts as next()
            pushAll(top->right);
        }
        return top->val;
    }
};

class Solution
{
public:
    bool findTarget(Node *root, int k)
    {
        if (root == NULL)
            return false;

        BSTIterator l(root, false); // for next()
        BSTIterator r(root, true);  // for before()

        int i = l.next();
        int j = r.next(); // eq. to r.before()

        while (i < j)
        {
            if (i + j == k)
            {
                return true;
            }
            else if (i + j < k)
            {
                i = l.next();
            }
            else
            {
                j = r.next();
            }
        }

        return false;
    }
};

int main()
{
    return 0;
}