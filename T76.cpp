#include<iostream>
#include<utility>
#include<string>
#include<unordered_map>
using namespace std;
string minWindow(string s, string t) {
    int m = s.length(), n = t.length();
    unordered_map<char, int> need;
    for(char c: t)
        need[c]++;
    int i = 0, needCnt = n;
    pair<int, int> res;
    res.first = 0;
    res.second = m + n + 1;
    for(int j = 0; j < m; j++)
    {
        char c = s[j];
        if(need[c] > 0)
            needCnt--;
        need[c]--;
        if(needCnt == 0)
        {
            bool update = false;
            while(true)
            {
                if(need[s[i]] == 0)
                {
                    update = true;
                    break;
                }
                need[s[i]]++;
                i++;
            }
            if(update && j - i + 1 < res.second - res.first + 1)
            {
                res.first = i;
                res.second = j;
            }
            need[s[i]]++;
            needCnt++;
            i++;
        }
    }    
    if(res.second != m + n + 1)
        return s.substr(res.first, res.second - res.first + 1);
    else
        return "";
}
int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    cout<<minWindow(s, t)<<endl;
    return 0;
}