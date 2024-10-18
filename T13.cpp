#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int romanToInt(string s) {
    unordered_map<char, int> hashmap;
    hashmap['I'] = 1;
    hashmap['V'] = 5;
    hashmap['X'] = 10;
    hashmap['L'] = 50;
    hashmap['C'] = 100;
    hashmap['D'] = 500;
    hashmap['M'] = 1000;
    int res = 0, n = s.length();
    int preNum = hashmap[s[0]];
    for(int i = 1; i < n; i++)
    {
        int curNum = hashmap[s[i]];
        if(preNum < curNum)
            res -= preNum;
        else
            res += preNum;
        preNum = curNum;
    }
    res += preNum;
    return res;
    // int res = 0, n=s.length();
    // for(int i=0;i<n;i++)
    // {
    //     if(s[i]=='I')
    //     {
    //         if(i+1<n&&(s[i+1]=='V'||s[i+1]=='X'))
    //         {
    //             if(s[i+1]=='V')
    //                 res+=4;
    //             else
    //                 res+=9;
    //             i++;
    //         }
    //         else
    //             res+=1;
    //     }
    //     else if(s[i]=='V')
    //         res+=5;
    //     else if(s[i]=='X')
    //     {
    //         if(i+1<n&&(s[i+1]=='L'||s[i+1]=='C'))
    //         {
    //             if(s[i+1]=='L')
    //                 res+=40;
    //             else
    //                 res+=90;
    //             i++;
    //         }
    //         else
    //             res+=10;
    //     }
    //     else if(s[i]=='L')
    //         res+=50;
    //     else if(s[i]=='C')
    //     {
    //         if(i+1<n&&(s[i+1]=='D'||s[i+1]=='M'))
    //         {
    //             if(s[i+1]=='D')
    //                 res+=400;
    //             else
    //                 res+=900;
    //             i++;
    //         }
    //         else
    //             res+=100;
    //     }
    //     else if(s[i]=='D')
    //         res+=500;
    //     else
    //         res+=1000;
    // }
    // return res;
}

int main()
{
    string s ="MCMXCIV";
    int res = romanToInt(s);
    cout<<res<<endl;
    return 0;
}