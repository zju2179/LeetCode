#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int maximumLength(string s) {
    int n = s.length();
    vector<int> groups[26];
    int cnt = 0;
    int i = 0;
    while (i < n)
    {
        int st = i;
        i++;
        while(i < n && s[i - 1] == s[i])
        {
            i++;
        }
        groups[s[st] - 'a'].push_back(i - st);
        // cout<<s[st]<<" "<<i-st<<endl;
    }
    int res = 0;
    for(i = 0; i < 26; i++)
    {
        vector<int> a = groups[i];
        if(!a.empty())
        {
            sort(a.rbegin(), a.rend());
            a.push_back(0);
            a.push_back(0);
            int l1 = a[0], l2 = a[1], l3 = a[2];
            res = max({res, l1 - 2, min(l1 - 1, l2), l3});
        }
    }
    if(res == 0)
        return -1;
    return res;
}
int main()
{
    string s = "aaaabbaaabccccccc";
    cout<<maximumLength(s)<<endl;
    return 0;
}