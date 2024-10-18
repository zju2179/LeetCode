#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e9;

vector<int> symetricNumber()
{
    vector<int> pal;
    for(int base = 1; base <= 99999; base *= 10) // base <= 99999
    {
        for(int i = base; i < base*10; i++)
        {
            int x = i;
            int t = i/10;
            while(t)
            {
                x = x*10 + t%10;
                t /= 10;
            }
            pal.push_back(x);
        }
        if(base <= 1000)
        {
            for(int i = base; i < base*10; i++)
            {
                int x = i;
                int t = i;
                while(t)
                {
                    x = x*10 + t%10;
                    t /= 10;
                }
                pal.push_back(x);
            }
        }
    }
    pal.push_back(N+1);
    return pal;
}
long long cost(vector<int> nums,vector<int> pal ,int i)
{
    int target = pal[i];
    long long res = 0;
    for(int x: nums)
        res += abs(target - x);
    return res;
}
long long minimumCost(vector<int>& nums) {
    long long res = 0;
    vector<int> pal = symetricNumber();
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int midloc = nums[(n-1)/2];
    int l = 0, r = pal.size() - 1;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(pal[mid] >= midloc)
            r = mid;
        else
            l = mid + 1;
    }
    if(pal[l] <= nums[n/2])
        return cost(nums,pal,l);
    return min(cost(nums,pal,l), cost(nums,pal,l-1));   
}

int main()
{
    vector<int> nums = {10,12,13,14,15};
    cout<<minimumCost(nums)<<endl;
    return 0;
}