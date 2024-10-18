#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize(2)
using namespace std;
vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
    int m = image.size(), n = image[0].size();
    vector<vector<int>> res(m, vector<int> (n, 0));
    vector<vector<int>> cnt(m, vector<int> (n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            bool ok = true;
            for(int x = i - 2; x <= i; x++) // 判断当前九宫格内的左右相邻的值是否满足条件
            {
                if(abs(image[x][j-2] - image[x][j-1]) > threshold || abs(image[x][j-1] - image[x][j])> threshold)
                {
                    ok = false;
                    break;
                } 
            }
            if(ok == false) continue;
            for(int y = j - 2; y <= j; y++) // 判断当前九宫格上下是否满足条件
            {
                if(abs(image[i-2][y] - image[i-1][y]) > threshold || abs(image[i-1][y] - image[i][y]) > threshold)
                {
                    ok = false;
                    break;
                }
            }
            if(ok == false) continue;

            int sum = 0;
            for(int x = i - 2; x <= i; x++)
            {
                for(int y = j - 2; y <= j; y++)
                {
                    sum += image[x][y];
                }
            }
            int avg = sum / 9;

            for(int x = i - 2; x <= i; x++)
            {
                for(int y = j - 2; y <= j; y++)
                {
                    res[x][y] += avg;
                    cnt[x][y]++;
                }
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(cnt[i][j])
                res[i][j] /= cnt[i][j];
            else
                res[i][j] = image[i][j];
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> a = {{5,6,7,10},{8,9,10,10},{11,12,13,10}};
    int threshold = 3;
    vector<vector<int>> res = resultGrid(a, threshold);
    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}