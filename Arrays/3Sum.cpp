// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that 
// i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

#include<bits/stdc++.h>
using namespace std;


// ******************************* M1(Using 2 pointer) *****************************
// T.C = O(n logn) + O(n*n)
// S.C = O(no. of unique triplets)
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin() , nums.end());    // to get the triplets in sorted order, so as to avoid dups
    if(nums.size() < 3){
        return {};
    }
    if(nums[0] > 0){ 
        return {};
    }
    vector<vector<int>> ans;
    for(int i = 0 ; i < nums.size() ; ++i){ 
        if(nums[i] > 0){     // any no. occurring after nums[i] will be a +ve no. greater than it. So, we can't make it 0
            break;
        }
        if(i > 0 && nums[i] == nums[i - 1]){   // we process only first occurrence of an element so as to avoid duplicates
            continue;
        }
        int low = i + 1 ;
        int high = nums.size() - 1; 
        while(low < high){
            int sum = nums[i] + nums[low] + nums[high];
            if(sum < 0){
                low++;
            } else if(sum > 0){ 
                high--;
            } else {
                ans.push_back({nums[i] , nums[low] , nums[high]});
                low++;
                high--;

                // ignore any other occurrence of same low and high so as to avoid duplicates
                while(low < high && nums[low] == nums[low-1]){   
                    low++;
                }
                while(low < high && nums[high] == nums[high+1]){
                    high--;
                }
            }
        }
    }
    return ans;
}


// ********************** M2: Using Hash Set *******************
// T.C = O(n*n)
 vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        for(int i=0; i<n; i++){
            unordered_set<int> hashSet;
            for(int j=i+1; j<n; j++){
                int req = -(nums[i] + nums[j]);
                if(hashSet.count(req)){
                    vector<int> v = {nums[i], nums[j], req};
                    sort(v.begin(), v.end());
                    s.insert(v); // we insert only the elements from i till j to choosing same element twice
                }
                hashSet.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
int main()
{
    return 0;
}