#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
const int N = 310;
bool dp[N];
bool f[N][N];
bool dfs(string s, unordered_map<string, bool> isInwordDict)
{
    if(s.empty())
        return true;
    bool res = false;
    int n = s.length();
    for(int i = 1; i < n; i++)
    {
        if(isInwordDict[s.substr(0, i)])
        {
            res = res || dfs(s.substr(i), isInwordDict);
        }
    }
    return res;
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, bool> isInwordDict;
    int n = s.length();
    for(string word: wordDict)
        isInwordDict[word] = true;
    return dfs(s, isInwordDict);
}
// bool dp[N];
// bool wordBreak(string s, vector<string>& wordDict) {
//     unordered_map<string, bool> isInwordDict;
//     int n = s.length();
//     dp[0] = true; // 表示空串一定能被wordDict表示出来
//     for(string word: wordDict)
//         isInwordDict[word] = true;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = i + 1; j <= n; j++)
//         {
//             cout<<i<<" "<<j<<" "<<s.substr(i, j - i)<<" "<<isInwordDict[s.substr(i,j)]<<endl;
//             if(dp[i] == true && isInwordDict[s.substr(i, j - i)] == true)
//                 dp[j] = true;
//         }
//     }
//     for(int i = 1; i <= n; i++)
//         cout<<dp[i]<<" ";
//     cout<<endl;
//     return dp[n];
// }
int main()
{
    string s = "catsandog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    cout<<wordBreak(s, wordDict);
    return 0;
}