#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

string reverseWords(string s) {
    string res = "";
    int i = 0;
    bool isfirst = true;
    vector<string> strs;
    while(i < s.length())
    {
        if(s[i] != ' ')
        {
            string temp = "";
            while(i<s.length() && s[i]!=' ')
            {
                temp += s[i];
                i++;
            }
            strs.push_back(temp);
        }
        i++;
    }
    for(int i = strs.size() - 1; i >= 0; i--)
    {
        string temp = strs[i];
        if(isfirst)
            isfirst = false;
        else
            res+=" ";
        res+=temp;
    }
    return res;
}
int main()
{
    string s = "the sky is blue";
    cout<<reverseWords(s)<<endl;
    return 0;
}