#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
int max_t, tn, tm;
int leftp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    tn = n / 2;
    tm = m;
    max_t = min(tn, tm);

    leftp = (n - max_t * 2) + (m - max_t);

    k -= leftp;

    if (k <= 0)
    {
        cout << max_t;
        return 0;
    }

    if (k % 3 != 0)
    {
        max_t -= (k / 3 + 1);
    }
    else
    {
        max_t -= k / 3;
    }

    if (max_t >= 0)
        cout << max_t;
    else
        cout << 0;
}