#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        // sort(intervals.begin(), intervals.end());

        vector<vector<int>>v;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(intervals[j][0]<=intervals[i][1])
                v[i].push_back(j);
            }
        }
        // sort(v.begin(), v.end());

        // for(int i=0; i<v.size(); i++){
        //     v[i].push_back(v)
        // }

        return v;
    }


int main(){
    vector<vector<int>>intervals{{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> v = merge(intervals);

    for(int i=0; i<v.size(); i++){
            for(int j=0; j<2; j++){
                cout<<v[i][j]<<" ";
            }
        }
    return 0;
}