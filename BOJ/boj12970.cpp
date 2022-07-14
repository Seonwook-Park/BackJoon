#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    if (k == 0)
    {
        for (int i = 0; i < n - 1; i++)
            cout << 'B';
        cout << 'A';
        return 0;
    }
    else if ((n / 2) * (n / 2 + n % 2) < k)
    {
        cout << -1;
        return 0;
    }
    else
    {
        int anum = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (n - i - 1 - anum > 0 && sum + n - i - 1 - anum <= k)
            {
                sum += n - i - 1 - anum++;
                cout << 'A';
            }
            else
            {
                cout << 'B';
            }
        }
    }
}