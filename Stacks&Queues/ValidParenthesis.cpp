// PROBLEM:
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
// determine if the input string is valid.

// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

#include<bits/stdc++.h>
using namespace std;

 bool isValid(string s) {
    int n = s.size();
    if(n%2!=0) return false;

    unordered_map<char, char>mp;
    mp.insert({')', '('});
    mp.insert({'}', '{'});
    mp.insert({']','['});
    
    stack<char> st;

    for(auto it: s){
        if(it == '(' || it=='{' || it=='['){
            st.push(it);
        }
        else if(st.empty()){
            return false;
        }
        else if(mp.count(it)==false){
            return false;
        }
        else if(mp[it]!=st.top()){
            return false;
        }
        else {
            st.pop();
        }
    }

    return st.empty();
}
int main()
{
    return 0;
}   