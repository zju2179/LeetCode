#include <iostream>
using namespace std;
const int N = 20;
int n;
bool st[N];
class StandardWeight{
public:
    int m, x;
    bool operator < (const StandardWeight a){
        return this->m < a.m;
    }
};
StandardWeight weights[N];
int ans = 0;
void dfs(int i, int sum)
{
    if(i >= n)
    {
        if(!st[sum])
        {
            ans++;
            st[sum] = true;
        }
        return;
    }
    for(int c = 0; c <= weights[i].x; c++)
    {
        dfs(i + 1, sum + c * weights[i].m);
    }
    
}
int main() {
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>weights[i].m;
    for(int i = 0; i < n; i++)
        cin>>weights[i].x;
    dfs(0, 0);
    cout<<ans<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")