#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int N = 1010;

class Point
{
public:
    int val;
    int idx;

    bool operator<(const Point b)
    {
        if (this->val < b.val)
            return true;
        else if (this->val > b.val)
            return false;
        else
            return this->idx < b.idx;
    }
};

Point a[N];

void PrintA(int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i].val << " " << a[i].idx << endl;
}

bool st[N];

void Shuffle(int n)
{
    sort(a + 1, a + n + 1);
    // for (int i = 1; i <= n; i++)
    //     cout << a[i].val << " " << a[i].idx << endl;
    int st_cnt = 0;
    vector<vector<Point>> res;
    while (st_cnt < n)
    {
        vector<Point> temp;
        int pre = -1;
        for (int i = 1; i <= n; i++)
        {
            if (!st[i] && a[i].val != pre)
            {
                temp.push_back(a[i]);
                st[i] = true;
                pre = a[i].val;
                st_cnt++;
            }
        }
        res.push_back(temp);
    }
    cout << res.size() << endl;
    for (vector<Point> s : res)
    {
        for (Point p : s)
        {
            cout << p.idx << " " << p.val << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].val;
        a[i].idx = i; // 给 idx 赋值为当前下标
    }

    Shuffle(n);

    return 0;
}