#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
struct Factor
{
    int fac, cnt;
    Factor(int fac_, int cnt_)
    {
        fac = fac_;
        cnt = cnt_;
    }
};

vector<Factor> prime_factors;
vector<int> divisors;

void getDivisors(int idx, int product)
{
    if (idx >= prime_factors.size())
    {
        divisors.push_back(product);
        return;
    }
    int fastPow = 1;
    for (int i = 0; i <= prime_factors[idx].cnt; i++)
    {
        getDivisors(idx + 1, product * fastPow);
        fastPow *= prime_factors[idx].fac;
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
            prime_factors.push_back(Factor(primes[i], cnt));
    }
    if (n > 1)
        prime_factors.push_back(Factor(n, 1));
    getDivisors(0, 1);
    sort(divisors.begin(), divisors.end());
    for (int i = 0; i < divisors.size(); i++)
    {
        cout << divisors[i];
        if (i < divisors.size() - 1)
            cout << " ";
    }

    return 0;
}