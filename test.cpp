#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3] ={4,3,9};
    int first = arr[0];
    int k;

    for(k=1; k<3; k++){
        if(arr[k]<first){
            arr[k-1]=arr[k];
        }
    }

    arr[k-1]=first;


    for(int i=0; i<3; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}