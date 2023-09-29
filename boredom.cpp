// SOLVED
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> m;
    int peak = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        peak = max(temp, peak);
        m[temp]++;
    }
    int ans = 0;
    // if a group in temp is greater value than the two surrounding, choose it and delete others
    for (int i = peak; i > 0; i--)
    {
        int val = m[i] * i;
        if (val >= m[i - 1] * (i - 1))
        {
            // delete the one below
            m[i - 1] = 0;
            ans += val;
        }
    }
    cout << ans;
}