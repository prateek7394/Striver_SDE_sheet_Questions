// PROBLEM
// You are given an array ‘arr’ of size ‘n’ which denotes the position of stalls.
// You are also given an integer ‘k’ which denotes the number of aggressive cows.
// You are given the task of assigning stalls to ‘k’ cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.

#include<bits/stdc++.h>
using namespace std;


bool isValid(vector<int> &stalls, int k, int dist){
    int count=1;
    int lastposition = stalls[0];
    for(int i=1; i<stalls.size(); i++){
        if(stalls[i]-lastposition>=dist){
            lastposition=stalls[i];
            count++;
        }

        if(count>=k){
            return true;
        }
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    // since we have at least 2 cows acc. to constraints
    int s = 1; 
    // minimum possible distance will be the min of diff b/w all consecutive elements
    // but here we are taking it as 1 for simplicity
    int e = stalls[n-1]-stalls[0]; // maximum possible distance
    int ans=0;

    while(s<=e){
        int mid = (s+e)/2;

        // check if k cows can be placed by taking mid as min distance
        bool check = isValid(stalls, k, mid);

        if(check==true){
            ans=mid; // potential ans
            s=mid+1; // check for any large possible value of mid(min distance)
        }
        else{
            e=mid-1;
        }
    }

    return ans;                    
}

int main()
{
    return 0;
}