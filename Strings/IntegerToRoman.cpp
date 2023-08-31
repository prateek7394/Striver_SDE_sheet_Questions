// PROBLEM:
// Given an integer, convert it to a roman numeral.

#include<bits/stdc++.h>
using namespace std;

// ============================ Method 1 ==============================

string intToRoman(int num) {
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string ans = "";
    for(int i=0; i<values.size(); i++){
        while(num>=values[i]){
            num-=values[i];
            ans+=strs[i];
        }
    }

    return ans;
}

// ============================ Method 2==============================

string intToRoman(int num) {
    vector<string>M = {"", "M", "MM", "MMM"};
    vector<string>C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string>X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string>I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    int m = num/1000;
    int c = (num%1000)/100;
    int x = (num%100)/10;
    int i = (num%10)/1;

    return M[m]+C[c]+X[x]+I[i];
}


int main()
{
    return 0;
}