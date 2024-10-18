#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;

int numberOfSubstrings(string s)
{
    int n = s.length();
    vector<int> zero_idx;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            zero_idx.push_back(i);
    zero_idx.push_back(n); // 加入一个哨兵
    int ans = 0;
    int i = 0; // s[zero_idx[i]] == '0'
    for (int left = 0; left < n; left++)
    {
        int p = zero_idx[i];
        int q = zero_idx[i + 1];
        if (s[left] == '1')
        {
            ans += p - left;
            left = zero_idx[i];
        }
        int cnt0 = 0, cnt1 = 0;
        for (int j = left; j <= p; j++)
        {
            if (s[j] == '0')
                cnt0++;
            else
                cnt1++;

            ans += ()
        }
        if (s[left] == '0')
            i++;
    }
}

int main()
{

    return 0;
}