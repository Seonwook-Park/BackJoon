#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n;
int a[1000100];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    v.push_back(a[0]);

    for (int i = 1; i < n; i++)
    {
        if (v.back() < a[i])
        {
            v.push_back(a[i]);
        }
        else
        {
            int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[pos] = a[i];
        }
    }

    cout << v.size();
}