// PROBLEM : https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// Median of an array is actually the middle element in the sorted array.

#include<bits/stdc++.h>
using namespace std;

// ------------- Method 1 (Brute Force)----------------
// T.C = O(n+m)
// S.C = O(n+m)

class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m=nums2.size();
        vector<int>v;
        int p1 = 0, p2=0;

        while(p1<n && p2<m){
            if(nums1[p1]<nums2[p2]){
                v.push_back(nums1[p1++]);
            }
            else{
                v.push_back(nums2[p2++]);
            }
        }

        while(p1<n){
            v.push_back(nums1[p1++]);
        }

        while(p2<m){
            v.push_back(nums2[p2++]);
        }

        int N = n+m;
        double median;

        if(N%2==0){
            median = (double)(v[N/2]+v[N/2-1])/2;
        }

        else{
            median = (double) v[N/2];
        }

        return median;
    }
};

// -------------------- Method 2(Space optimised) -----------------
// T.C = O(m+n)
// S.C = O(1)

class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n=nums2.size();
        int i=0, j=0, count=0;
        int N = m+n;
        int idx1= N/2, idx2 = N/2-1;
        int ele1 = -1, ele2 = -1;

        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                if(count==idx1) ele1 = nums1[i];
                else if(count==idx2) ele2 = nums1[i];
                i++;
            }
            else{
                if(count==idx1) ele1 = nums2[j];
                else if(count==idx2) ele2 = nums2[j];
                j++;
            }
            count++;
        }

        while(i<m){
            if(count==idx1) ele1 = nums1[i];
            else if(count==idx2) ele2 = nums1[i];
            i++;
            count++;
        }

        while(j<n){
            if(count==idx1) ele1 = nums2[j];
            else if(count==idx2) ele2 = nums2[j];
            j++;
            count++;
        }

        if(N%2==0){
            return  (double)(ele1+ele2)/2;
        }

        return (double) ele1;

    }
};

int main()
{
    vector<int> arr1 = {2, 5, 9, 19};
    vector<int> arr2 = {1, 4, 21};
    Solution1 s1;
    cout<< s1.findMedianSortedArrays(arr1, arr2) << endl;
    Solution2 s2;
    cout<< s2.findMedianSortedArrays(arr1, arr2) << endl;
    return 0;
}