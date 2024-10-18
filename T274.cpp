#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int hIndex(vector<int>& citations) {
    //可以用二分查找进行优化
    sort(citations.begin(),citations.end());
    int h = citations[citations.size()-1];
    while(h)
    {
        int l=0, r=citations.size();
        while(l<r)
        {// 二分找到x第一个大于等于h的值，其下标就是cnt，即h大于等于的citations[i]的个数
            int mid=(l+r)>>1;
            if(citations[mid] >= h)
                r=mid;
            else//citations[mid]<=h
                l=mid+1;
        }
        int cnt = citations.size()-l;
        if(cnt>=h)
        {
            return h;
        }
        h--;
    }
    return 0;
    // sort(citations.begin(), citations.end(), greater<int> ());
    // int res=0;
    // int h = citations[0];
    // bool flag=false;
    // while(!flag&&h)
    // {
    //     int cnt=0;
    //     for(int x: citations)
    //     {
    //         if(h<=x)
    //         {
    //             cnt++;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     if(cnt >= h)
    //     {
    //         flag=true;
    //         res=h;
    //     }
    //     h--;
    // }
    // return res;
}

int main()
{
    vector<int> nums={3,0,6,1,5};
    int res=hIndex(nums);
    cout<<res<<endl;
    return 0;
}