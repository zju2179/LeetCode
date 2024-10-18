#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int N = 1010;
char pad[N][N];
string convert(string s, int numRows) {
    // for(int i = 0; i < N; i++)
    //     for(int j = 0; j < N; j++)
    //         pad[i][j] = '#';
    // bool isVertical = true;
    // string res = "";
    // int i = 0, col = 0;
    // while(i < s.length())
    // {
    //     if(isVertical == true)
    //     {
    //         for(int j = 0; j < numRows - 1; j++)
    //         {
    //             pad[j][col] = s[i++];
    //         }
    //         isVertical = false;
    //     }
    //     else
    //     {
    //         int row = numRows - 1;
    //         for(int cnt = 0; cnt < numRows - 1; cnt++)
    //         {
    //             pad[row--][col++] = s[i++];
    //         }
    //         isVertical = true;
    //     }
    // }
    // for(int i = 0; i < numRows; i++)
    // {
    //     for(int j = 0; j < s.length(); j++)
    //     {
    //         if(pad[i][j] != '#'&&pad[i][j] != '\0')
    //         {
    //             res+=pad[i][j];
    //         }
    //     }
    // }
    // return res;
}
int main()
{
    string s = "ABCDEF";
    int numRows = 6;
    string res = convert(s, numRows);
    cout<<res<<endl;
    return 0;
}