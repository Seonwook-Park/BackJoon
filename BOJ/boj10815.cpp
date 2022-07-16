#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<int> san;
vector<int> num;

int binarySearch(int target, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (san[mid] == target)
            return 1;
        else if (san[mid] > target)
            end = mid - 1;
        else if (san[mid] < target)
            start = mid + 1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        san.push_back(tmp);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }

    sort(san.begin(), san.end());
    for (int i = 0; i < m; i++)
    {
        cout << binarySearch(num[i], 0, n - 1) << " ";
    }
}
