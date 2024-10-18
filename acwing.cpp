#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
const int N = 100010;
int a[N];
int cnt[N];
int main()
{
    int left = 0;
    int n = 0;
    int res = 1;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    // unordered_set<int> seq;
    for(int right = 0; right < n; right++)
    {
        cnt[a[right]]++;
        if(cnt[a[right]] > 1)
        {
            res = max(res, right - left);
            while(cnt[a[right]] > 1)
            {
                cnt[a[left]]--;
                left++;
            }
        }
        else if(right == n - 1)
            res = max(res, right - left + 1);   
    }
    cout<<res<<endl;
    return 0;
}