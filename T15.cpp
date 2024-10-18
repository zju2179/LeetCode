#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    if(n < 3)
        return {};
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for(int i = 0 ; i < n ; i++)
    {
        if(nums[i] > 0)
            return res;
        if(i > 0 && nums[i] == nums[i-1])
            continue;   //去重，因为如果和nums[i-1]一样，那么后面的子区间里的l和r已经被扫描过了，不需要重复扫描
        int l = i + 1 , r = n - 1;
        while(l < r)
        {
            if(nums[i] + nums[l] + nums[r] == 0)
            {
                res.push_back({nums[i], nums[l], nums[r]});
                while(l + 1 < r && nums[l] == nums[l+1])
                    l++;
                while(r - 1 > l && nums[r] == nums[r-1])
                    r--;
                l++;
                r--;
            }
            else if(nums[i] + nums[l] + nums[r] > 0)
                r--;
            else
                l++;
        }
    }
    return res;
}
int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(nums);
    for(auto row : res)
        cout<<row[0]<<" "<<row[1]<<" "<<row[2]<<endl;
    return 0;
}