// The lower bound is the smallest index, ind, where arr[ind] >= x. 
// But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

// The upper bound is the smallest index, ind, where arr[ind] > x.
// But if any such index is not found, the upper bound algorithm returns n i.e. size of the given array. 

// The main difference between the lower and upper bound is in the condition. 
// For the lower bound the condition was arr[ind] >= x and but in the case of the upper bound, it is arr[ind] > x.


#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] >= x) {
            ans = mid; // maybe an answer(potential ans)
            high = mid - 1; //look for smaller index on the left
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x) {
            ans = mid; // maybe an answer
            high = mid - 1; //look for smaller index on the left
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main()
{
    return 0;
}