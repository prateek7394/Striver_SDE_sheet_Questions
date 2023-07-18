#include <bits/stdc++.h>
using namespace std;

int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
        vector<int>v1, v2;
        v1.push_back(nums1[0]);
        v2.push_back(nums2[0]);
        int v1m = 1;
        for(int i=1; i<n; i++){
            int curr = v1[v1.size()-1];
            if(nums1[i]<curr && nums2[i]<curr){
                int s = v1.size();
                v1m = max (v1m, s);
                v1.clear();
                v1.push_back(min(nums1[i], nums2[i]));
                continue;
            }
            if(nums1[i]==curr){
                v1.push_back(nums1[i]);
            }

            else if(nums2[i]==curr){
                v1.push_back(nums2[i]);
            }
            else if(nums1[i]>curr && nums2[i]<curr){
                v1.push_back(nums1[i]);
            }
            else if(nums2[i]>curr && nums1[i]<curr){
                v1.push_back(nums2[i]);
            }
            else{
                v1.push_back(min(nums1[i], nums2[i]));
            }
        }
    if(v1.size() > v1m){
        v1m = v1.size();
    }

    int v2m=1;
        for(int i=1; i<n; i++){
            int curr = v2[v2.size()-1];
            if(nums1[i]<curr && nums2[i]<curr){
                int s = v2.size();
                v2m = max(v2m, s);
                v2.clear();
                v2.push_back(min(nums1[i], nums2[i]));
                continue;
            }
            if(nums1[i]==curr){
                v2.push_back(nums1[i]);
            }

            else if(nums2[i]==curr){
                v2.push_back(nums2[i]);
            }
            else if(nums1[i]>curr && nums2[i]<curr){
                v2.push_back(nums1[i]);
            }
            else if(nums2[i]>curr && nums1[i]<curr){
                v2.push_back(nums2[i]);
            }
            else{
                v2.push_back(min(nums1[i], nums2[i]));
            }
        }

    if(v2.size() > v2m){
        v2m = v2.size();
    }

    return max(v1m, v2m);
        
}

int main()
{
    vector<int> nums1 = {8,7,4};
    vector<int> nums2 = {13,4,4};

    int ans = maxNonDecreasingLength(nums1, nums2);
    cout<<ans;

    return 0;
}