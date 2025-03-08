#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 26;
int g[N][N];
int inDegree[N];
vector<vector<char>> services = {{'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'D', 'A'}};
bool inQueue[N];
bool TopoSort(){
    int start = -1;
    for(int i = 0; i < N; i++){
        if(inDegree[i] == 0){
            start = i;
            break;
        }
    }
    if(start == -1) return true; // 没用入度为0的顶点，说明有环
    queue<int> q;
    q.push(start);
    inQueue[start] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < N; i++){
            if(g[cur][i]){
                inDegree[i]--;
                if(inDegree[i] == 0 && !inQueue[i]){
                    q.push(i);
                    inQueue[i] = true;
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(!inQueue[i] && inDegree[i] > 0)  return true;
    }
    return false;
}
int main(){
    for(auto &service: services){
        int a = service[0] - 'A', b = service[1] - 'A';
        g[a][b] = 1;
        inDegree[b]++;
    }
    cout<<TopoSort()<<endl;
    return 0;
}