#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int n, m;
map<int, int> basket;
vector<int> num;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        if (basket.find(tmp) == basket.end())
        {
            basket.insert(make_pair(tmp, 1));
        }
        else
        {
            basket[tmp] = basket[tmp] + 1;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        if (basket.find(num[i]) != basket.end())
            cout << basket[num[i]] << " ";
        else
            cout << 0 << " ";
    }
}
