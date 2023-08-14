// Problem:
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.



//********** M1: Using unordered_map and only 1 iteration ******
// T.C = O(n)
// S.C. = O(n)

#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> mp;
        vector<int>ans;

        for(auto  it: nums){
            mp[it]++;
            if(mp[it]==n/3+1){
                // once freq of an element becomes >n/3 we push it into ans list
                ans.push_back(it);
            }

//  OBSERVATION: Maximum no. of majority elements in an array can be 2
            if(ans.size()==2){
                // once we get 2 majority elements we break the loop
                break;
            }
        }

        return ans;
}


// ********* M2: Using Moore's Voting Algo for >n/3 **************
// T.C = O(2n), S.C = O(1)
// Explaination:
// Since we know that there can be atmost 2 majority elements , so we can assume 2 elements
// ele1 and ele2 and apply the method we used for >n/2 solution

vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1, ele2;
        int cnt1=0, cnt2=0;
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(cnt1==0 && nums[i]!=ele2){
                // Here we also ensure that the same element is not already stored in other variable
                // before storing it in current variable by checking nums[i]!=ele2
                cnt1 = 1;
                ele1 = nums[i];
            }

            else if(cnt2==0 && nums[i]!=ele1){
                cnt2 = 1;
                ele2 = nums[i];
            }

            else if(nums[i]==ele1){
                cnt1++;
            }

            else if(nums[i]==ele2){
                cnt2++;
            }

            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1=0, cnt2=0;

        for(int i=0; i<n; i++){
            if(nums[i]==ele1){
                cnt1++;
            }
            else if(nums[i]==ele2){
                cnt2++;
            }
        }

//      Verify
        if(cnt1>n/3){
            ans.push_back(ele1);
        }

        if(cnt2>n/3){
            ans.push_back(ele2);
        }

        return ans;
}


int main()
{
    
    return 0;
}