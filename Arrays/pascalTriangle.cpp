#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>prevTemp = {1};
        ans.push_back(prevTemp);

        for(int i=1; i<numRows; i++){
            vector<int>temp;
            for(int j=0; j<=i; j++){
                if(j==0){
                    temp.push_back(prevTemp[j]);
                }
                else if(j==i){
                    temp.push_back(prevTemp[j-1]);
                }
                else{
                    temp.push_back(prevTemp[j-1] + prevTemp[j]);
                }
            }
            ans.push_back(temp);
            prevTemp=temp;
        }
        return ans;
}

int main(){
    vector<vector<int>> result= generate(5);
    for(auto value: result){
        for(int i=0; i<value.size(); i++){
            cout<<value[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}