// Given an array of integers nums and an integer target, return indices of the two numbers such that 
// they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

#include<bits/stdc++.h>
using namespace std;


// *************************** Method 1 (Using unordered_map)************************
// T.C = O(n)
// S.C = O(n) + O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int,int> m;
    vector<int> ans;
    
    for(int i=0; i<n; i++){
        auto it = m.find(target-nums[i]); // O(1)
        if(it!=m.end()){
            ans.push_back(i);
            ans.push_back(m[target-nums[i]]);
            break;
        }
        m[nums[i]] = i;
    }

    return ans;

}

// ********************************** M2(Using 2 pointers) *****************
// T.C = O(n logn) + 2 * O(n)
// S.C = O(n) + O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        v.push_back({nums[i], i});
    }
    sort(v.begin(), v.end());
    auto i=0, j=n-1;

    vector<int> ans;

    while(i<j){
        int sum = v[i].first + v[j].first;
        if(sum==target){
            ans.push_back(v[i].second);
            ans.push_back(v[j].second);
            break;
        }
        else if(sum<target) i++;
        else j--;
    }

    return ans;

}
int main()
{
    return 0;
}
