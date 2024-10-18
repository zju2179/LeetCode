#include<iostream>
#include<vector>
using namespace std;
int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left;
    for(int i=0;i<n;i++)
        left.push_back(1);
    vector<int> right = left;
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(ratings[i]>ratings[i-1])
            left[i]=left[i-1]+1;
    }
    for(int i=n-1;i>0;i--)
    {
        if(ratings[i-1]>ratings[i])
            right[i-1]=right[i]+1;
    }
    for(int i=0;i<n;i++)
    {
        res+=max(left[i],right[i]);
    }
    return res;
}
int main()
{
    vector<int> ratings={1,0,2};
    int res = candy(ratings);
    cout<<res<<endl;
    return 0;
}