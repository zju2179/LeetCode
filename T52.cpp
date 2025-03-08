#include <iostream>
#include <vector>
using namespace std;

int totalNQueens(int n) {
    vector<bool> col(n, false);
    vector<bool> diag1(2 * n - 1, false); // 从左下到右上的对角线，r + c是一个定值，且 0 <= r + c <= 2n - 2 < 2n - 1
    vector<bool> diag2(2 * n - 1, false); // 从左上到右下的对角线，r - c是一个定值，且 0 <= r - c + n - 1 <= 2n - 2 < 2n - 1
    int res = 0;
    auto dfs = [&](auto&& dfs, int r){
        if(r == n){
            res++;
            return;
        }
        for(int c = 0; c < n; c++){
            int rc = r - c + n - 1;
            if(!col[c] && !diag1[r + c] && !diag2[rc]){
                col[c] = diag1[r + c] = diag2[rc] = true;
                dfs(dfs, r + 1);
                col[c] = diag1[r + c] = diag2[rc] = false;
            }
        }
    };
    dfs(dfs, 0);
    return res;
}

int main(){
    int n;
    cin >> n;
    cout << totalNQueens(n) << endl;
    return 0;
}