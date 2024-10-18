#include<iostream>
using namespace std;
int strStr(string haystack, string needle) {
    int i = 0, j = 0;
    while(i < haystack.size())
    {
        if(j >= needle.size())
        {
            return i - j;
        }
        if(haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else
        {//
            i = i - j + 1;
            j = 0;
        }
    }
    if(j >= needle.size())
        return i - j;
    return -1;
}
int main()
{
    string s,t;
    s = "a";
    t = "a";
    cout<<strStr(s,t)<<endl;
    return 0;
}