// PROBLEM:
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
// The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and 
// eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead 
// and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

#include<bits/stdc++.h>
using namespace std;

// T.C = O(n) + O(n*maxElement)
// S.C = O(1)

bool check(vector<int>&piles, long long k, int h){
    long long totalHours=0;
    for(int it: piles){
        totalHours+= ceil((double) it / (double) k); 
        // IMPORTANT: to find ceil convert int into double
        if(totalHours>h){
            return false;
        }
    }
    return true;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int maxi = INT_MIN;
    for(auto it: piles){
        maxi = max(maxi, it);
    }

    int s = 1, e = maxi; // maximum speed can be equal to the maximum no. of bananas in the pile
    int ans = -1;

    while(s<=e){
        int mid = s+(e-s)/2;
        bool isValid = check(piles, mid, h);

        if(isValid==true){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    return ans;
}

int main()
{
    return 0;
}