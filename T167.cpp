#include<iostream>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    vector<int> res;
    for(int i = 0; i < n; i++)
    {
        int x = target-numbers[i];
        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = (l + r + 1)>>1;
            if(x >= numbers[mid])
                l = mid;
            else
                r = mid - 1;
        }
        if(numbers[l] == x)
        {
            int index1 = min(i, l) + 1;
            int index2 = max(i, l) + 1;
            res.push_back(index1);
            res.push_back(index2);
            return res;
        }
    }
    return res;
}

int main()
{
    vector<int> numbers = {0,0,3,4};
    int target = 0;
    vector<int> res = twoSum(numbers, target);
    cout<<res[0]<<" "<<res[1];
    return 0;
}