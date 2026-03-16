#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vector<bool> bs;
vll primes;
ll sieve_size;

// =======================
// SIEVE
// =======================
void sieve(ll upperbound)
{
    sieve_size = upperbound + 1;
    bs.assign(sieve_size, true);

    bs[0] = bs[1] = false;

    for (ll i = 2; i <= upperbound; ++i)
    {
        if (bs[i])
        {
            primes.push_back(i);
            if (i <= upperbound / i)
            {
                for (ll j = i * i; j <= upperbound; j += i)
                    bs[j] = false;
            }
        }
    }
}

// =======================
// PRIME FACTORS
// =======================
vll primeFactors(ll N)
{
    vll factors;

    for (int i = 0; i < (int)primes.size() && primes[i] <= N / primes[i]; ++i)
    {
        while (N % primes[i] == 0)
        {
            factors.push_back(primes[i]);
            N /= primes[i];
        }
    }

    if (N != 1)
        factors.push_back(N);

    return factors;
}

// =======================
// MAIN
// =======================
int main()
{

    cout << "Starting sieve...\n";

    sieve(10000020); // พอสำหรับ 10000019^2

    cout << "Sieve done!\n";
    cout << "Largest prime = " << primes.back() << "\n\n";

    ll test = 10000019LL * 10000019LL;

    cout << "Factoring: " << test << "\n";

    vll result = primeFactors(test);

    for (ll x : result)
        cout << "> " << x << "\n";

    return 0;
}
