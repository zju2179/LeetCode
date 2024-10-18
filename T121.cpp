#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int cost=INT_MAX,profit=0;
    for(int price:prices)
    {
        cost=min(cost,price);
        profit=max(profit, price-cost);
    }
    return profit;
}

int main()
{
    vector<int> nums={7,1,5,3,6,4};
    int res = maxProfit(nums);
    cout<<res<<endl;
    return 0;
}