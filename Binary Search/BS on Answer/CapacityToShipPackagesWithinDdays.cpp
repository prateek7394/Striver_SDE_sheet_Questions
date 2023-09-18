// PROBLEM:
// A conveyor belt has packages that must be shipped from one port to another within 'days' days.

// The ith package on the conveyor belt has a weight of weights[i]. 
// Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
// We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt 
// being shipped within 'days' days.

#include<bits/stdc++.h>
using namespace std;

int reqDays(int capacity, vector<int>& weights){
    int d=1, currWeight=0;
    for(int i=0;i<weights.size(); i++){
        currWeight+= weights[i];
        if(currWeight>capacity){
            d++;
            currWeight = weights[i];
        }
    }
    return d;
}
int shipWithinDays(vector<int>& weights, int days) {
    int totalWt = 0, maxi = INT_MIN;
    for(auto it: weights){
        totalWt+= it;
        maxi = max(maxi, it);
    }
    // Minimum capacity of ship must be equal to the max weight present in
    // the ship so that all the weights can be shipped.
    
    // Maximum capacity of ship required can be equal total weight to be
    // carried when days = 1

    int low = maxi, high = totalWt;
    int ans=-1;

    while(low<=high){
        int mid = (low+high)/2;
        int requiredDays = reqDays(mid, weights);

        if(requiredDays<=days){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}

int main()
{
    return 0;
}