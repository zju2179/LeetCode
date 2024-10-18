#include<iostream>
#include<vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> answers;
    int pre[100010], post[100010];
    pre[0]=1;
    post[n-1]=1;
    for(int i=1;i<n;i++)
    {
        pre[i]=pre[i-1]*nums[i-1];
    }
    for(int i=n-2;i>=0;i--)
    {
        post[i]=post[i+1]*nums[i+1];
    }
    for(int i=0;i<n;i++)
    {
        answers.push_back(pre[i]*post[i]);
    }
    return answers;
}
int main()
{
    vector<int> nums={1,2,3,4};
    vector<int> res=productExceptSelf(nums);
    bool isfirst=true;
    for(int x:res)
    {
        if(!isfirst)
            cout<<" ";
        else
            isfirst=false;
        cout<<x;
    }
    return 0;
}