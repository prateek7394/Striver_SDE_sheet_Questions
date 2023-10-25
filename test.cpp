#include<bits/stdc++.h>
using namespace std;

double getElement(int n, int r){
    if(r==0 || n==0){
        return 1;
    }

    double ans = 1;

    for(int i=0; i<r; i++){
        ans*=(n-i);
        ans/=(r-i);
    }

    cout<<ans<<endl;
    return ans;
}

vector<int> getRow(int rowIndex) {
    if(rowIndex==0){
        return {1};
    }

    vector<int> v;

    cout<<getElement(29,3)<<endl;

    return v;
}

int main()
{
    vector<int> buglu ={1,2,3,4,5};
    for(auto i: buglu){
        cout<<i<<" ";
    }
    getRow(29);
    return 0;
}