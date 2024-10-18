#include<iostream>
#include<vector>

using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=nums1.size()-1;
    m--;
    n--;
    while(n>=0)
    {
        while(m>=0&&nums1[m]>nums2[n])
        {
            swap(nums1[m--],nums1[i--]);
        }
        //出while循环后必有nums1[m]<=nums2[n]
        swap(nums2[n--],nums1[i--]);
    }
    // int i=0,j=0;
    // vector<int> res;
    // while(i<m&&j<n)
    // {
    //     if(nums1[i]<=nums2[j])
    //     {
    //         res.push_back(nums1[i]);
    //         i++;
    //     }
    //     else
    //     {//nums1[i]>nums2[j]
    //         res.push_back(nums2[j]);
    //         j++;
    //     }
    // }
    // while(i<m)
    // {
    //     res.push_back(nums1[i++]);
    // }
    // while(j<n)
    // {
    //     res.push_back(nums2[j++]);
    // }
    // nums1=res;
}
int main()
{
    vector<int> nums1,nums2;
    nums1={1,2,3,0,0,0};
    nums2={2,5,6};
    int m=3,n=3;
    merge(nums1,m,nums2,n);
    bool isfirst=true;
    for(int i=0;i<m+n;i++)
    {
        if(!isfirst)
            cout<<" ";
        else
            isfirst=false;
        cout<<nums1[i];
    }
    cout<<endl;
    return 0;
}