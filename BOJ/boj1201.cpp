#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, m, k;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    if (m + k > n + 1 || k * m < n)
    {
        cout << -1;
        return 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            v.push_back(i + 1);
        }
        int idx = 0;

        for (int i = 1; i <= m; i++)
        {
            int tmp = min(idx + k, n - m + i);
            reverse(v.begin() + idx, v.begin() + tmp);

            idx = tmp;
        }

        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
    }
}
