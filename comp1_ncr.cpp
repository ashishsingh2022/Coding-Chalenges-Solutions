#include <bits/stdc++.h>

#define ll long long
const int N = 1000001;
using namespace std;

ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(ll p)
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

ll Binomial(ll N, ll R, ll p)
{
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}
 
// Driver Code
int init()
{
    ll p = 1000000007;
    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);

    cout << Binomial(N, R, p) << endl;
    cout << Binomial(N, R, p) << endl;
}