#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
const int N = 10010;
bool st[N];
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<unordered_map<char, int>> maps;
    for(string s: strs)
    {
        unordered_map<char, int> f;
        for(char c: s)
            f[c]++;
        maps.push_back(f);
    }
    vector<vector<string>> res;
    for(int i = 0; i < maps.size(); i++)
    {
        vector<string> temp;
        if(!st[i])
        {
            temp.push_back(strs[i]);
            st[i] = true;
        }
        for(int j = i + 1; j < maps.size(); j++)
        {
            if(!st[j] && maps[j] == maps[i])
            {
                temp.push_back(strs[j]);
                st[j] = true;        
            }
        }
        if(temp.size())
            res.push_back(temp);
    }
    return res;
}
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for(auto group: res)
    {
        for(auto s: group)
            cout<<s<<" ";
        cout<<endl;
    }
    return 0;
}