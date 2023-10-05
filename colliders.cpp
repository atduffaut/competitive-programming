// SOLVED
#include <iostream>
#include <vector>
#include <unordered_set>
#define ll long long
using namespace std;

vector<ll> getFactors(ll x, vector<bool> primes)
{
    vector<ll> ans;
    // prime factors of input number x from i = 2 to sqrt(x)
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i != 0)
            // x not divisible by i
            continue;
        if (primes[i])
            // x divisible by i and i is a prime, so store this factor
            ans.push_back(i);
        if (primes[x / i])
            // x divisible by i, and x/i is a prime, store this factor
            ans.push_back(x / i);
    }
    if (ans.size() == 0)
        ans.push_back(x);
    return ans;
}

int main()
{
    // fast io for C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<bool> primes(n + 1, true);
    // do the prime sieve of eratosthenes from 0 -> n to find all the primes in that range
    primes[0] = false;
    primes[1] = false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                // every number divisible by our prime (i) cannot be prime
                primes[j] = false;
            }
        }
    }
    vector<ll> active(n + 1, 0);
    unordered_set<ll> on;
    while (m--)
    {
        string s;
        cin >> s;
        ll c;
        cin >> c;
        if (s == "+")
        {
            // check the set to see if collider is already on
            if (on.find(c) != on.end())
            {
                cout << "Already on" << endl;
            }
            else
            {
                // check if any factors of c are turned on by another collider
                vector<ll> factors = getFactors(c, primes);
                int conflict = 0;
                for (auto f : factors)
                {
                    if (active[f] != 0)
                    {
                        conflict = active[f];
                        break;
                    }
                }
                // if no conflict found, turn on all the factors of c with the value of c and insert into set
                if (conflict == 0)
                {
                    cout << "Success" << endl;
                    on.insert(c);
                    for (auto f : factors)
                        active[f] = c;
                }
                else
                    cout << "Conflict with " << conflict << endl;
            }
        }
        else
        {
            // check if c is already off
            if (on.find(c) != on.end())
            {
                // if not, turn off all the prime factors of c
                vector<ll> factors = getFactors(c, primes);
                cout << "Success" << '\n';
                on.erase(c);
                for (auto f : factors)
                    active[f] = 0;
            }
            else
            {
                cout << "Already off" << endl;
            }
        }
    }
}