#include<iostream>
#include<vector>
using namespace std;
int squareSum(int n)
{
    int sum = 0;
    while(n)
    {
        int factor = n % 10;
        n /= 10;
        sum += factor*factor;
    }
    return sum;
}
bool isHappy(int n) {
    int slow = n, fast = n;
    do{
        slow = squareSum(slow);
        fast = squareSum(fast);
        fast = squareSum(fast);
        if(slow == 1)
            return true;
    }while(slow != fast);
    return false;
}
int main()
{
    int n;
    cin>>n;
    cout<<isHappy(n)<<endl;
    return 0;
}