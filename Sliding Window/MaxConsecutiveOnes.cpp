// PROBLEM : https://leetcode.com/problems/max-consecutive-ones-iii/
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array
//  if you can flip at most k 0's.

#include<bits/stdc++.h>
using namespace std;


// ------------------------- M1(My approach) -------------------------
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0, zeroCount=0;
        int i=0, j=0;

        for(j=0; j<nums.size(); j++){
            if(nums[j]==0){
                zeroCount++;
            }
            while(zeroCount>k){
                if(nums[i]==0){
                    zeroCount--;
                }
                i++;
            }

            ans = max(ans, j-i+1);
        }

        return ans;
    }
};

// ------------------------- M2(More optimal approach) -------------------------
// Whenever the flip count K of current range (i.e., still i to j) is greater or equals to 0,
// it means we can possibly expand our window.
// When k<0, it means we have flipped more than the allowed no. of flips, so we increment i along with j,
// so that the window size remains constant.
// Basically, we increment the window size whenever it's possible and rest of the time we keep it constant 
// and equal to the max possible size.
// At last we return the (j-i-1)+1 = (j-i) as j has crossed range of array.

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==0){
                k--;
            }
            if(k<0){
                if(nums[i]==0){
                    k++;
                }
                i++;
            }
            j++;
        }
        return j-i;
    }
};

int main()
{
    return 0;
}