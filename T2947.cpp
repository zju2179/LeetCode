#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isVowels(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
    return false;
}
int beautifulSubstrings(string s, int k) {
    int n = s.length();
    int res = 0;
    for(int l = 0; l < n; l++)
    {
        int vowels = 0, consonants = 0;
        for(int r = l; r < n; r++)
        {
            if(isVowels(s[r]))
                vowels++;
            else
                consonants++;
            if(vowels == consonants && (vowels*consonants)%k == 0)
                res++;
        }
    }
    return res;
}
int main()
{
    string s = "baeyh";
    int k = 2;
    cout<<beautifulSubstrings(s,k)<<endl;
    return 0;
}