// PROBLEM:
// Given a string s, sort it in decreasing order based on the frequency of the characters. 
// The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

#include<bits/stdc++.h>
using namespace std;

// ======================== M1: Using Max Heap ==========================
// T.C = O(n logn)

string frequencySort(string s) {
    unordered_map<char,int>mp;
    for(auto it: s){
        mp[it]++;
    }

    priority_queue<pair<int, char>> pq;
    for(auto it: mp){
        pq.push({it.second, it.first});
    }

    string ans = "";
    while(!pq.empty()){
        char c = pq.top().second;
        int freq = pq.top().first;

        // for(int i=0; i<freq; i++)
        //     ans+=c;

        ans+=string(freq, c); // this creates a string containing char c with freq no. of times
        pq.pop();
    }

    return ans;
}

// ======================== M2: By sorting ==========================
// T.C = O(N + KlogK), where K is the no. of distinct elements in the string


string frequencySort(string s) {
    unordered_map<char,int>mp;
    for(auto it: s){
        mp[it]++;
    }

    vector<pair<int, char>> v; //{freq, char}
    for(auto it: mp){
        v.push_back({it.second, it.first});
    }

    sort(v.begin(), v.end(), [](auto &a, auto &b){
        // sort in decreasing order of freq;
        return a.first>b.first;
    });

    string ans;
    for(auto &[freq, c]: v){
        // append function appends a given char with freq no. of times in the string
        ans.append(freq, c);
    }
    return ans;
}

// ======================== M3: Using Bucket Sort ==========================
// T.C = O(n)

string frequencySort(const string& s) {
    int n = s.size();
    unordered_map<char, int> cnt;
    for (char c : s)  cnt[c]++;
    
    vector<string> bucket(n+1, "");
    for (auto [c, f] : cnt)
        bucket[f].append(f,c);
    
    string ans;
    for (int freq = n; freq >= 1; freq--){
    // insert the characters in decreasing order of freq
        if(!bucket[freq].empty()){
            ans+=bucket[freq];
        }
    }
    return ans;
}



int main()
{
    return 0;
}