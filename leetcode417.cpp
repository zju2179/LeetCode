#include <iostream>
#include <unordered_map>

using namespace std;
bool isFu(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return false;
    return true;
}
bool isYuanValid(unordered_map<char, int> cnt)
{
    if (cnt['a'] >= 1 && cnt['e'] >= 1 && cnt['i'] >= 1 && cnt['o'] >= 1 && cnt['u'] >= 1)
        return true;
    return false;
}
long long countOfSubstrings(string word, int k)
{
    long long res = 0;
    int n = word.length();
    int left = 0, fu_cnt = 0;
    unordered_map<char, int> yuan_cnt;
    int last_fu = -1, cur_fu = 0;
    for (int right = 0; right < n; right++)
    {
        if (isFu(word[right]))
            fu_cnt++;
        else
            yuan_cnt[word[right]]++;

        if (isYuanValid(yuan_cnt) && fu_cnt == k)
        {
            int start_ = left;
            // bool isMove = false;
            while (left <= right && isYuanValid(yuan_cnt) && fu_cnt == k)
            {
                if (isFu(word[left]))
                {
                    last_fu = cur_fu;
                    cur_fu = left;
                    fu_cnt--;
                }
                else
                    yuan_cnt[word[left]]--;
                left++;
            }
            res += (left - start_);
            cout << start_ << " " << left << " " << right << endl;
            left--;
        }
        else if (fu_cnt > k)
        {
            left = last_fu + 1;
            cout << last_fu << " " << cur_fu << endl;
        }
    }
    return res;
}
int main()
{
    string word = "ieaouqqieaouqq";
    int k = 1;
    long long res = countOfSubstrings(word, k);
    cout << res << endl;
    return 0;
}