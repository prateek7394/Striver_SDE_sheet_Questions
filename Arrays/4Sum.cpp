// PROBLEM : https://leetcode.com/problems/4sum/description/

#include<bits/stdc++.h>
using namespace std;

// --------------------- M1(By using set to avoid duplicates) ------------------------

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    set<vector<int>> st;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int l = j+1;
            int r = n-1;
            
            while(l<r){
                long long sum = (long long)nums[i]+nums[j]+nums[l]+nums[r];
                
                if(sum==target){
                    st.insert({nums[i], nums[j], nums[l], nums[r]});
                    l++;
                    r--;
                }
                
                else if(sum>target){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
    }
    
    vector<vector<int>>ans(st.begin(), st.end());
    
    return ans;
    
}

// --------------------- M2(Without using set and using 2 pointer technique) ------------------------

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> ans;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            long long remain = (long long) target-(nums[i]+nums[j]); // we typecasted to long long so that it may not exceed the range of INT

            int l = j+1;
            int r = n-1;
            
            while(l<r){
                if(nums[l]+nums[r]==remain){
                    ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                    l++;
                    r--;

                    // to avoid duplicates, skip any other occurrences
                    while(l<r && nums[l-1]==nums[l]) l++;
                    while(l<r && nums[r+1]==nums[r]) r--;
                    
                }
                else if(nums[l]+nums[r]>remain){
                    r--;
                }
                else{
                    l++;
                }
            }
            while(j+1<n && nums[j]==nums[j+1]) j++; // to avoid duplicates, skip any other occurrences
        }

        while(i+1<n && nums[i]==nums[i+1]) i++; // to avoid duplicates, skip any other occurrences
    }
    return ans;
}

int main()
{
    return 0;
}