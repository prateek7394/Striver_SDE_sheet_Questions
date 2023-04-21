#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int n = arr.size();
    
    int maxPro = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}

int main(){
    
    return 0;
}