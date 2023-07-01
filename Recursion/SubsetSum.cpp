// PROBLEM:
// Given a list arr of N integers, print sums of all subsets in it.

#include <bits/stdc++.h>
using namespace std;

// T = O(2^n)
// S.C = O(2^n)
void powerSet(vector<int> arr, int sum, vector<int> &ans)
{
    if (arr.size() == 0)
    {
        ans.push_back(sum);
        return;
    }

    int op1 = sum;
    int op2 = sum;
    op2 += arr[0];

    arr.erase(arr.begin() + 0);

    powerSet(arr, op1, ans);
    powerSet(arr, op2, ans);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    powerSet(arr, 0, ans);
    return ans;
}

int main()
{
    return 0;
}