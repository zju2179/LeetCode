#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], b[N];
int sum(int x[]){
    int res = 0;
    for(int i = 0; i < n; i++)
        res += x[i];
    return res;
}
int MaxXor(){
    int sumA = sum(a), sumB = sum(b);
    int res = 0;
    for(int i = 0; i < n; i++){
        int tmp = sumA - a[i];
        res = max(res, tmp ^ sumB);
        tmp = sumB - b[i];
        res = max(res, sumA ^ tmp);
    }
    return res;
}
int main(){
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    cout<<MaxXor()<<endl;
    return 0;
}