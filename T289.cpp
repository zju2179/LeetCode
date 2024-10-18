#include<iostream>
#include<vector>
using namespace std;
const int N = 35;
bool change[N][N];
int d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = board[0].size();
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int live_cnt = 0;
            for(int k = 0; k < 8; k++)
            {
                int x = i + d[k][0], y = j + d[k][1];
                if(x>=0 && x<m && y>=0 && y<n && board[x][y] == 1)
                    live_cnt++;
            }
            if(board[i][j] == 1)
            {
                if(live_cnt == 2 || live_cnt == 3)
                    board[i][j] |= 2; // 用第二低位的bit位来表示是否该细胞仍存活
            }
            else
            {
                if(live_cnt == 3)
                    board[i][j] |= 2;
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] & 2 == 2)
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
    // for(int i = 0; i < m; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         int live_cnt = 0;
    //         for(int k = 0; k < 8; k++)
    //         {
    //             int x = i + d[k][0], y = j + d[k][1];
    //             if(x>=0 && x<m && y>=0 && y<n && board[x][y] == 1)
    //                 live_cnt++;
    //         }
    //         if(board[i][j] == 1)
    //         {
    //             if(live_cnt < 2 || live_cnt > 3)
    //                 change[i][j] = true;
    //         }
    //         else
    //         {
    //             if(live_cnt == 3)
    //                 change[i][j] = true;
    //         }
    //     }
    // }
    // for(int i = 0; i < m; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         if(change[i][j])
    //             board[i][j] = 1 - board[i][j];
    //     }
    // }
}
int main()
{

    return 0;
}