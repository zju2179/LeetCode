#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int res = 0;
    int n = height.size();
    int i = 0, j = n - 1;
    while(i < j)
    {
        int cur_Area = (j - i) * min(height[i], height[j]);
        res = max(res, cur_Area);
        if(height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return res;
}

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height)<<endl;
    return 0;
}