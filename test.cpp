#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPSArray(string s)
{
    int n = s.size();
    vector<int> lps(n);

    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1]; // move len pointer to lps value at prev idx
            }
        }
    }

    return lps;
}
vector<int> search(string pat, string txt)
{
    int p = pat.size(), t = txt.size();
    vector<int> lps = computeLPSArray(pat);

    int i = 0, j = 0;
    vector<int> ans;

    while (i < t)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }

        else if (j > 0)
        {
            j = lps[j - 1];
        }
        else
        {
            i++;
        }

        if (j == p)
        {
            ans.push_back(i - j + 1);
            cout<<i<<" "<<j<<endl;
        }
    }

    return ans;
}

int main()
{

    string txt = "abcbabca";
    string pat = "bc";
    cout<<pat[2]<<endl;
    // vector<int> v = search(pat, txt);

    // for(auto it: v){
    //     cout<<it<<" ";
    // }
    return 0;
}