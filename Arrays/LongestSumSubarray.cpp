// PROBLEM:
// Given an array and a sum k, we need to find the length of the longest subarray that sums to k.
// NOTE: The array can contain BOTH positive and negative elements


// APPROACH:
// In this approach, we find the prefix sum till each index and store it in a hash map.
// Suppose prefix_sum = x and we find a sum equal to (x-k) is already present in map
// => The sum of remaining elements is equal to k. So, we update the maxlen with the length of this subarray.
// Also, if the prefix_sum is itself equal to k, then we update the maxlen 

#include<bits/stdc++.h>
using namespace std;

// T.C = O(n*1) but it can be O(n*n) in worst case when using an unordered_map

int getLongestSubarray(vector<int>& a, int k){
    long long preSum=0;
    unordered_map<long long, int> mp;
    int maxlen = 0;

    for(int i=0; i<a.size(); i++){
        preSum+=a[i];

        if(preSum==k){
            maxlen = max(maxlen, i+1);
        }

        else if(mp.count(preSum-k)){
            maxlen = max(maxlen, i-mp[preSum-k]);
        }

        if(mp.count(preSum)==false){
            // EDGE CASE : 
            // If the array contains zeroes, then we only store a value
            // for the first time in hash map and don't update it as we need longest possible
            // subarray. E.g. {2,0,0,3}
            mp[preSum] = i;
        }
    }

    return maxlen;
}

// NOTE: If the array contains only +ve elements then, the optimal solution will be using Sliding window
// with time complexity O(2n)

int main()
{
    return 0;
}