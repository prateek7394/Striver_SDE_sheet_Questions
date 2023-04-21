#include<bits/stdc++.h>
using namespace std;

//  Using DNF Algorithm: 
// --> Uses only one traversal of array 
// --> T=O(n)

    void sortColors(vector<int>& arr) {
        int n=arr.size();

        // [0,low-1]-> contains 0s
        // [low, mid-1]-> contains 1s
        // [mid, high]-> unsorted part of array containing 0s,1s and 2s
        // [high+1, n-1]-> contains 2s
        int low=0;
        int mid=0;
        int high=n-1;

        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }

            else if(arr[mid]==1){
                mid++;
            }
            else if(arr[mid]==2){
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }

// Better Solution: Using count of 0s, 1s and 2s
// T=O(2*n) SC=O(1)
   void sortColors(vector<int>& nums) {
        int n=nums.size();
        
        int c0=0, c1=0, c2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) c0++;
            else if(nums[i]==1) c1++;
            else c2++;
        }

        for(int i=0; i<c0; i++){
            nums[i]=0;
        }
        for(int i=c0; i<c0+c1; i++){
            nums[i]=1;
        }
        for(int i=c0+c1; i<n; i++){
            nums[i]=2;
        }
    }
int main(){
    
    return 0;
}