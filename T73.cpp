#include<iostream>
#include<vector>
#include<utility>
using namespace std;
const int N = 210;
bool st[N][N];
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    // vector<pair<int,int>> points;
    // for(int i = 0; i < m; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         if(matrix[i][j] == 0)
    //             points.push_back({i, j});
    //     }
    // }
    // for(pair<int, int> point: points)
    // {
    //     int i = point.first, j = point.second;
    //     for(int row = 0; row < m; row++)
    //         matrix[row][j] = 0;
    //     for(int col = 0; col < n; col++)
    //         matrix[i][col] = 0;
    // }
    bool row0_flag = false, col0_flag = false;
    for(int i = 0; i < m; i++)
        if(matrix[i][0] == 0)
        {
            col0_flag = true;
            break;
        }
    for(int j = 0; j < n; j++)
        if(matrix[0][j] == 0)
        {
            row0_flag = true;
            break;
        }
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = matrix[0][j] = 0; //标记第i行和第j列必须全部置0
            }
        }
    }
    for(int i = 1; i < m; i++)
    {
        if(matrix[i][0] == 0)
        {
            for(int j = 1; j < n; j++)
                matrix[i][j] = 0;
        }
    }
    for(int j = 1; j < n; j++)
    {
        if(matrix[0][j] == 0)
        {
            for(int i = 1; i < m; i++)
                matrix[i][j] = 0;
        }
    }
    if(row0_flag)
    {
        for(int j = 0; j < n; j++)
            matrix[0][j] = 0;
    }
    if(col0_flag)
    {
        for(int i = 0; i < m; i++)
            matrix[i][0] = 0;
    }
}

int main()
{

    return 0;
}