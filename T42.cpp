#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int N = 20010;
int trap(vector<int>& height) {
    // // 按行求
    // int res = 0, n=height.size();
    // int maxH=0;
    // for(int i=0;i<n;i++)
    //     maxH=max(maxH, height[i]);
    // for(int i=1;i<=maxH;i++)
    // {
    //     int temp = 0;
    //     bool isfirst=true;
    //     for(int j=0;j<n;j++)
    //     {
    //         if(!isfirst&&height[j]<i)
    //         {
    //             temp++;
    //         }
    //         if(height[j]>=i)
    //         {
    //             isfirst=false;
    //             res+=temp;
    //             temp=0;
    //         }
    //     }
    // }
    // return res;

    // // 按列求
    // int n = height.size(), res=0;
    // int maxLeft[N], maxRight[N];
    // maxLeft[0]=maxRight[n-1]=0;
    // for(int i=1;i<n;i++)
    //     maxLeft[i]=max(maxLeft[i-1],height[i-1]);
    // for(int i=n-2;i>=0;i--)
    //     maxRight[i]=max(maxRight[i+1], height[i+1]);
    // for(int i=0;i<n;i++)
    // {
    //     int max_left=maxLeft[i];
    //     // for(int j=i-1;j>=0;j--)
    //     //     if(height[j]>max_left)
    //     //         max_left=height[j];
    //     int max_right=maxRight[i];
    //     // for(int j=i+1;j<n;j++)
    //     //     if(height[j]>max_right)
    //     //         max_right=height[j];
    //     int minBothH=min(max_left, max_right);
    //     if(minBothH>height[i])
    //         res+=(minBothH-height[i]);
    // }
    // return res;
    
    // 单调栈（基于括号匹配思想，左墙就是左括号，右墙就是右括号）
    int cur = 0;
    stack<int> s; // stack中存储所有可能积水的左墙的下标
    int res = 0;
    while(cur < height.size())
    {
        while(!s.empty() && height[cur] > height[s.top()])
        {// 若有可能积水的左墙存在且可能的右墙的高度大于可能的左墙高度，则此时有积水
            int i = s.top();
            s.pop();
            if(s.empty())
                break;
            int distance = cur - s.top() - 1;
            int minBoundH = min(height[s.top()], height[cur]);
            res += (minBoundH-height[i]) * distance;
            // cout<<s.top()<<" "<<i<<" "<<cur<<" "<<res<<endl;
        }
        // 当处理完所有可能形成积水的左墙以后，将当前墙的高度入栈，可能作为新左墙与后面的墙形成积水
        s.push(cur);
        cur++;
    }
    return res;
}

int main()
{
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    int res=trap(height);
    cout<<res<<endl;
    return 0;
}