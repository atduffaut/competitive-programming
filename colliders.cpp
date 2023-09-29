// SOLVED
#include <iostream>
#include <vector>
#include <unordered_set>
#define ll long long
using namespace std;

vector<ll> getFactors(ll x, vector<bool> primes)
{
    vector<ll> ans;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i != 0)
            continue;
        if (primes[i])
            ans.push_back(i);
        if (primes[x / i])
            ans.push_back(x / i);
    }
    if (ans.size() == 0)
        ans.push_back(x);
    return ans;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<bool> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
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
            if (on.find(c) != on.end())
            {
                cout << "Already on" << endl;
            }
            else
            {
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
            if (on.find(c) != on.end())
            {
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