// PROBLEM:
// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.

#include<bits/stdc++.h>
using namespace std;

// // ============================ M1: Naive solution ====================================

void rotate(string &s){
    int n = s.size();
    char temp = s[0];
    for(int i=0; i<n-1; i++){
        s[i]=s[i+1];
    }
    s[n-1]=temp;
}
bool rotateString(string s, string goal) {
    int n = s.size();
    if(s.size()!=goal.size()){
        return false;
    }

    for(int j=0; j<n; j++){
        rotate(s);
        if(s==goal){
            return true;
        }
    }

    return false;
}

// ====================================== Method 2 ================================

bool rotateString(string s, string goal) {
    return s.size()==goal.size() && (s+s).find(goal)!=string::npos;
}

int main()
{
    return 0;
}