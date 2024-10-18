#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int res = 1e5;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = target - nums[i] - nums[j];
            int l = 0, r = n - 1;
            int min_d = 1e5;

            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (x <= nums[mid])
                {
                    r = mid;
                    if (x == nums[mid])
                    {
                        if (mid != i && mid != j)
                            return target;
                    }
                    else
                    {
                        if (mid != i && mid != j && min_d > abs(x - nums[mid]))
                        {
                            min_d = abs(x - nums[mid]);
                            res = nums[mid] + nums[i] + nums[j];
                        }
                    }
                }
                else
                {
                    l++;
                    if (mid != i && mid != j && min_d > abs(x - nums[mid]))
                    {
                        min_d = abs(x - nums[mid]);
                        res = nums[mid] + nums[i] + nums[j];
                    }
                }
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {-1, 2, 1, 4};
    int target = 1;
    cout << threeSumClosest(nums, target) << endl;
    return 0;
}