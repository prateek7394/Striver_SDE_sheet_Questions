// PROBLEM:
// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. 
// The returned string should only have a single space separating the words. Do not include any extra spaces.

#include<bits/stdc++.h>
using namespace std;

// ************************** M1: My Approach **********
string reverseWords(string s) {
    string ans = "";
    for(int i=s.size()-1; i>=0; i--){
        string temp = "";
        while(i>=0 && s[i]==' '){
            i--;
        }
        while(i>=0 && s[i]!=' '){
            temp+=s[i];
            i--;
        }
        reverse(temp.begin(), temp.end());
        if(!temp.empty()){
            ans+=temp;
            ans+=" ";
        }
    }

    ans.pop_back();

    return ans;
}

// ***************************** M2:  Split words then Join words in reverse order *************
// Here we use stringstream to read individual strings from the the input stream(original string)
// T.C = O(n)
// S.C = O(n)
string reverseWords(string s) {
    vector<string> words;
    stringstream ss(s);
    string tmp;
    while (ss >> tmp)
        words.push_back(tmp);

    string ans;
    for (int i = words.size() - 1; i >= 0; --i) {
        if (i != words.size() - 1) ans += " ";
        ans += words[i];
    }
    return ans;
}

// ******************************* M3: Reverse whole string then reverse word by word***********************************
// T.C = O(n)
// S.C = O(1)
string reverseWords(string s) {
    reverse(s.begin(), s.end());
    
    int i = 0, j = 0, n = s.size(), lastIndex = 0;
    
    while(j < n){
        // Find the starting index of the word: Skipping empty spaces before the word.
        while(j < n && s[j] == ' ') j++;
        
        int startIndex = i;
        
        // Store the complete word... : 
        while(j < n && s[j] != ' '){
            s[i++] = s[j++];
            lastIndex = i;
        }
        
        // Reverse the word
        reverse(s.begin() + startIndex, s.begin() + lastIndex);
        s[i++] = ' '; // after every word we need space [" "]
    }
    
    // Resize the string to the last index of the last word: to avoid empty spaces at the end.
    s.resize(lastIndex);
    return s;
}

int main()
{
    return 0;
}