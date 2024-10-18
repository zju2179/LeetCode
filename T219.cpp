#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
// typedef pair<int, int> Point;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> hashset;
    for(int i = 0; i < nums.size(); i++)
    {
        if(hashset.count(nums[i])) // 若前面k个元素中有和当前元素相等的，这两个元素必然下标相差要小于等于k
            return true;
        hashset.insert(nums[i]);
        if(hashset.size() > k)
            hashset.erase(nums[i - k]); // 维持hashset中只有k个元素
    }
    return false;
    // vector<pair<int, int>> a;
    // int n = nums.size();
    // for(int i = 0; i < n; i++)
    //     a.push_back(pair{nums[i], i});
    // sort(a.begin(), a.end());
    // for(int i = 0; i + 1 < n; i++)
    // {
    //     if(a[i].first == a[i+1].first && abs(a[i].second - a[i+1].second) <= k)
    //         return true;
    // }
    // return false;
}
int main()
{
    vector<int> nums = {1,2,3,1};
    int k = 3;
    cout<<containsNearbyDuplicate(nums, k)<<endl;
    return 0;
}