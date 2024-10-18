#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
void stringSplit(string str, const char split, vector<string> &res)
{
    istringstream iss(str); //字符串输入流
    string token;   // 接受缓冲区
    while(getline(iss, token, split)) // 按split分割
    {
        res.push_back(token);
    }
}
int lengthOfLastWord(string s) {
    int n = s.length();
    int rear = -1, res = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            rear = i;
        if(rear >= 0)
        {
            while(rear >= 0&&((s[rear]>='a'&&s[rear]<='z')||(s[rear]>='A'&&s[rear]<='Z')))
            {
                res++;
                rear--;
            }
            break;
        }
    }
    return res;
}
int main()
{
    string s = "luffy is still joyboy";
    cout<<lengthOfLastWord(s);
    return 0;
}