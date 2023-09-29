// SOLVED
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            m[temp - i]++;
        }
        long long total = 0;
        for (auto i : m)
        {
            long long temp = i.second;
            total += (temp * (temp - 1) / 2);
        }
        cout << total << endl;
    }
}