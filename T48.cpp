#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int times = 0; //统计循环的轮数，最大为n/2，若为奇数，最里层那一轮是不需要移动的因此不是(n+1)/2
    int n = matrix.size();
    while(times < (n >> 1))
    {
        int len = n - (times << 1); //第times轮的边界的长度
        for(int i = 0; i < len - 1; i++)
        {
            int temp = matrix[times][times+i];
            matrix[times][times+i] = matrix[times+len-1-i][times];
            matrix[times+len-1-i][times] = matrix[times+len-1][times+len-1-i];
            matrix[times+len-1][times+len-1-i] = matrix[times+i][times+len-1];
            matrix[times+i][times+len-1] = temp;
        }
        times++;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    for(auto row: matrix)
    {
        for(int x: row)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}