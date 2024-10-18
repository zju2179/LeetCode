#include<iostream>
#include<vector>
using namespace std;
const int N = 20;
bool visit[N][N];
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size(), n = matrix[0].size();
    bool up, down, left, right;
    up = down = left = false;
    right = true;
    int cnt = 1, i = 0, j = 0;
    res.push_back(matrix[i][j]);
    visit[i][j] = true;
    while(cnt < m*n)
    {
        if(right)
        {
            if(j + 1 >= n || visit[i][j+1] == true)
            {
                right = false;
                down = true;
            }
            else
            {
                j++;
                // cout<<matrix[i][j]<<endl;
                res.push_back(matrix[i][j]);
                visit[i][j] = true;
                cnt++;
            }
        }
        else if(down)
        {
            if(i + 1 >= m || visit[i+1][j] == true)
            {
                down = false;
                left = true;
            }
            else
            {
                i++;
                // cout<<matrix[i][j]<<endl;
                res.push_back(matrix[i][j]);
                visit[i][j] = true;
                cnt++;
            }
        }
        else if(left)
        {
            if(j - 1 < 0 || visit[i][j-1] == true)
            {
                left = false;
                up = true;
            }
            else
            {
                j--;
                // cout<<matrix[i][j]<<endl;
                res.push_back(matrix[i][j]);
                visit[i][j] = true;
                cnt++;
            }
        }
        else if(up)
        {
            if(i - 1 < 0 || visit[i-1][j] == true)
            {
                up = false;
                right = true;
            }
            else
            {
                i--;
                // cout<<matrix[i][j]<<endl;
                res.push_back(matrix[i][j]);
                visit[i][j] = true;
                cnt++;
            }
        }
        else
            break;
    }
    return res;
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = spiralOrder(matrix);
    for(int x: res)
        cout<<x<<" ";
    return 0;
}