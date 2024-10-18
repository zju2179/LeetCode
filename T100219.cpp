#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
bool compare(string a, string b)
{
    return a.length() < b.length();
}
int maxPalindromesAfterOperations(vector<string>& words) {
    int res = 0;
    unordered_map<char, int> cnt;
    for(string s: words)
    {
        for(char c: s)
            cnt[c]++;
    }    
    int left = 0;
    for(auto it: cnt)
        left += it.second / 2;
    sort(words.begin(), words.end(), compare);
    for(string s: words)
    {
        int m = s.length();
        if(left < m / 2)    break;
        left -= m / 2;
        res++;    
    }
    return res;
}

int main()
{

    return 0;
}