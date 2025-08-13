#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    vector<vector<int>> nums;
    string str;
    // 输入示例，读入不定长数组，可能中间带有逗号
    // 1,2,3
    // 4,5
    // 7,8,9,10,11
    // while(getline(cin, str))
    // {
    //     stringstream ss(str);
    //     while(getline(ss, str, ',')) // 去除读入数据的',' 得到每个数字
    //     {
    //         v.push_back(stoi(str));
    //     }

    //     // printVector(v);
    //     if(v.empty())
    //         break;
    //     nums.push_back(v);
    //     v.clear();
    // }

    // 读入数字的不定长数组，用空格分隔开
    // 1 2 3
    // 4 5
    // 6 9 1 7 8 2
    int val;
    while (cin >> val)
    {
        v.push_back(val);
        if (getchar() == '\n')
        {
            v.clear();
        }
        nums.push_back(v);
    }
    cout << "做一个 git 测试" << endl;
    for (vector<int> a : nums)
    {
        for (int x : a)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}