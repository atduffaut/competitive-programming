// SOLVED
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> pre(v.size(), 0);
    pre[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + v[i];
    }
    sort(v.begin(), v.end());
    vector<ll> sorted(v.size(), 0);
    sorted[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        sorted[i] = sorted[i - 1] + v[i];
    }
    int m;
    cin >> m;
    while (m--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            if (l < 2)
            {
                cout << pre[r - 1] << '\n';
                continue;
            }
            cout << pre[r - 1] - pre[l - 2] << '\n';
        }
        else
        {
            if (l < 2)
            {
                cout << sorted[r - 1] << '\n';
                continue;
            }
            cout << sorted[r - 1] - sorted[l - 2] << '\n';
        }
    }
}