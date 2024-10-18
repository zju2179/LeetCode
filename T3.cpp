#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int lengthOfLongestSubstring(string s) {
    if(s.length() == 0)   return 0;
    if(s.length() == 1)
        return 1;
    unordered_map<char, int> hashmap;
    int res = 0;
    int l = 0, r = 0;
    hashmap[s[l]] = 1;
    for(r = 1; r < s.length(); r++)
    {
        if(hashmap[s[r]] > 0)
        {
            while(s[l] != s[r])
            {
                hashmap[s[l]]--;
                l++;
            }
            hashmap[s[l++]]--;
            hashmap[s[r]] = 0;
        }
        hashmap[s[r]]++;
        cout<<l<<" "<<r<<endl;
        res = max(res, r - l + 1);
    }
    return res;
}
int main()
{
    string s = "abcabcbb";
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}