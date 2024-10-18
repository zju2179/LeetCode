#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
int f(string s, int k)
{   // 假设s的子串中有m种字符, 那么就寻找长度为m*k的子串中哪些子串满足每个字符都出现k次
    int n = s.length(), res = 0;
    for(int m = 1; m <= 26; m++)
    {
        int size = m*k;
        if(size > n)    break;
        unordered_map<char, int> cnt;
        unordered_map<int,int> cc;
        for(int i = 0; i < size; i++)
            cnt[s[i]]++;
        for(auto it: cnt)
            cc[it.second]++;
        if(cc[k] == m)
            res++;
        for(int i = size, j = 0; i < n; i++, j++)
        {
            cc[cnt[s[i]]]--;
            cnt[s[i]]++;
            cc[cnt[s[i]]]++;

            cc[cnt[s[j]]]--;
            cnt[s[j]]--;
            cc[cnt[s[j]]]++;
            
            if(cc[k] == m)
                res++;
        }
    }
    return res;
    // int n = s.length(), res = 0;
    // if(n < k)   return 0;
    // for(int m = 1; m <= 26; m++)
    // {
    //     int size = m * k; // 滑动窗口长(子串)
    //     if(size > n)    break;
    //     unordered_map<char, int> hashmap;
    //     for(int i = 0; i < size; i++)
    //         hashmap[s[i]]++;
    //     bool isAdd = true;
    //     for(auto it: hashmap)
    //     {
    //         int cnt = it.second;
    //         if(cnt != k)
    //         {
    //             isAdd = false;
    //             break;
    //         }
    //     }
    //     if(isAdd)   res++;
    //     for(int i = size, j = 0; i < n; i++, j++)
    //     {
    //         char in_ = s[i], out = s[j];
    //         hashmap[in_]++;
    //         hashmap[out]--;
    //         bool flag = true;
    //         for(auto it: hashmap)
    //         {
    //             int cnt = it.second;
    //             if(cnt != k && cnt != 0)
    //             {
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         if(flag)   res++;
    //     }
    // }
    // return res;
}
int countCompleteSubstrings(string word, int k) {
    int n = word.length();
    int i = 0, res = 0;
    while(i < n)
    {
        int st = i;
        string s = "";
        s += word[st];
        i++;
        while(i < n && abs((int)word[i] - (int)word[i-1])<=2)
        {
            s += word[i];
            i++;
        }
        cout<<s<<endl;
        res += f(s, k);
    }
    return res;
}

int main()
{
    string word = "ca";
    int k = 1;
    int res = countCompleteSubstrings(word, k);
    cout<<res<<endl;
    return 0;
}