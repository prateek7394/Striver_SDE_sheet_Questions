#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach:
// T.C = O(nlogn) + O(n^2)
// S.C = O(n)

vector<vector<int>> mergeIntervals(vector<vector<int>> & arr) {

    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        int start = arr[i][0], end = arr[i][1];

        //since the current interval already lies in the last inserted interval, skip it 
        if (!ans.empty()) {
            if (start <= ans.back()[1]) {
                continue;
            }
        }

        // check if other intervals can be merged with current interval
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
            else{
                // subsequent intervals can not be merged as the array is sorted acc. to start
                break;
            }
        }

        ans.push_back({start, end});
    }

    return ans;
}


// Optimised Approach:
// T.C = O(nlogn) + O(n)
// S.C = O(n)


vector<vector<int>> merge(vector<vector<int>> &arr){
    int n = arr.size();
    if(n==0 || n==1){
        return arr;
    }

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    vector<int> temp = arr[0];

    for(auto it: arr){
        if(it[0]<= temp[1]){
            temp[1] = max(temp[1], it[1]);
        }
        else{
            ans.push_back(temp);
            temp = it;
        }
    }

    ans.push_back(temp);
    return ans;
}

int main(){
    vector<vector<int>>intervals{{1,2}, {2,3}, {3,4}, {1,3}};
    // vector<vector<int>> v = mergeIntervals(intervals);
    vector<vector<int>> v = merge(intervals);

    for(int i=0; i<v.size(); i++){
        cout<<"[ ";
        for(int j=0; j<2; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"] ";
    }
    return 0;
}