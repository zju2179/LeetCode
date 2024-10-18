#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    int n = board.size();
    for(auto row: board)
    {
        unordered_map<char, int> hashmap;
        for(char c: row)
            if(c!='.')
                hashmap[c]++;
        for(auto it: hashmap)
        {
            if(it.second > 1)
                return false;
        }
    }
    for(int col = 0; col < n; col++)
    {
        unordered_map<char, int> hashmap;
        for(int i = 0; i < n; i++)
            if(board[i][col] != '.')
                hashmap[board[i][col]]++;
        for(auto it: hashmap)
        {
            if(it.second > 1)
                return false;
        }
    }
    for(int id = 0; id < 3; id++)//访问每个3*3的九宫格
    {
        unordered_map<char, int> hashmap;
        for(int i = 0; i < 3; i++)
        {
            for(int j = id*3; j < id*3+3; j++)
            {
                if(board[i][j] != '.')
                    hashmap[board[i][j]]++;
            }
        }
        for(auto it: hashmap)
            if(it.second > 1)
                return false;
    }
    for(int id = 0; id < 3; id++)//访问每个3*3的九宫格
    {
        unordered_map<char, int> hashmap;
        for(int i = 3; i < 6; i++)
        {
            for(int j = id*3; j < id*3+3; j++)
            {
                if(board[i][j] != '.')
                    hashmap[board[i][j]]++;
            }
        }
        for(auto it: hashmap)
            if(it.second > 1)
                return false;
    }
    for(int id = 0; id < 3; id++)//访问每个3*3的九宫格
    {
        unordered_map<char, int> hashmap;
        for(int i = 6; i < 9; i++)
        {
            for(int j = id*3; j < id*3+3; j++)
            {
                if(board[i][j] != '.')
                    hashmap[board[i][j]]++;
            }
        }
        for(auto it: hashmap)
            if(it.second > 1)
                return false;
    }
    return true;
}

int main()
{
    vector<vector<char>> board;

    return 0;
}