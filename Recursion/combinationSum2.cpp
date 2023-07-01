#include<bits/stdc++.h>
using namespace std;

void helper( int currIdx, vector<int> &temp, vector<vector<int>> &ans, vector<int> &arr, int target){
    if(target == 0){
        ans.push_back(temp);
        return;
    }

    for(int i = currIdx; i<arr.size(); i++){
        if( i>currIdx && arr[i] == arr[i-1]){
            continue;
            // make recursive call only for first occurrence of an element
            // and skip further occurrences of that element 
        }
        if(arr[i]>target){
            break;
            // since the array is sorted, therefore once we get an element>target
            // we don't check for further elements as they are > currElement
        }
        temp.push_back(arr[i]);
        helper(i+1, temp, ans, arr, target-arr[i]);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    vector<vector<int>> ans;
    helper(0, temp, ans, candidates, target);
    return ans;
}

int main()
{
    return 0;
}