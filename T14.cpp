#include<iostream>
#include<vector>
#include<string>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    int minLength = strs[0].length();
    for(string s: strs)
        minLength = min(minLength, (int)s.length());
    string res = "";
    for(int i = 0; i < minLength; i++)
    {
        char target = strs[0][i];
        bool isRes = true;
        for(int j = 1; j < strs.size(); j++)
        {
            if(target != strs[j][i])
            {
                isRes = false;
                break;
            }
        }
        if(isRes)
            res+=target;
        else
            break;
    }
    return res;
}
int main()
{
    vector<string> strs = {"dog","racecar","car"};
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}