#include<bits/stdc++.h>
using namespace std;

    int maxSubarrays(vector<int> &arr)
    {
        int x = INT_MAX;
        for (auto it : arr) x &= it;
        if (x != 0) return 1;
        int ans = 0;
        
        for (int it : arr)
        {
            if (x == 0)
                x = it;
            else
                x &= it;
            if (x == 0)
                ans++;
        }
        return ans;
    }

int main()
{
    return 0;
}