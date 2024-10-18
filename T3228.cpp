#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int maxOperations(string s)
{
    int cnt1 = 0;
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            cnt1++;
        if (i - 1 >= 0 && s[i] == '0' && s[i - 1] == '1')
            res += cnt1;
    }
    return res;
}

int main()
{
    string s = "1001101";
    cout << maxOperations(s) << endl;
    return 0;
}