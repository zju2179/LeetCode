#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    int i = 0;
    vector<vector<int>> res;
    for(auto it: intervals)
        cout<<it[0]<<" "<<it[1]<<endl;
    while(i < n)
    {
        int st = i;
        i++;
        int left = intervals[st][0];
        int right = intervals[st][1];
        while(i < n && (intervals[i][0] <= right || right >= intervals[i][1]))
        {
            right = max(right, intervals[i][1]);
            left = min(left, intervals[i][0]);
            i++;
        }
        if(st+1 == i)
            res.push_back(intervals[st]);
        else
        {
            
            res.push_back({left, right});
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = merge(intervals);
    for(auto inter:res)
        cout<<inter[0]<<" "<<inter[1]<<endl;
    return 0;
}