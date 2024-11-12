#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1010;
bool isPrime[N];
vector<int> primes;
void getPrime(int n)
{
    fill(isPrime, isPrime + N, true);
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i + i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    getPrime((int)sqrt(1.0 * n));
    for (int i = 0; i < primes.size() && n > 1; i++)
    {
        int cnt = 0;
        while (n > 1 && n % primes[i] == 0)
        {
            cnt++;
            n /= primes[i];
        }
        if (cnt > 0)
            cout << primes[i] << " " << cnt << endl;
    }
    if (n > 1)
        cout << n << " " << 1 << endl;
    return 0;
}