#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
vector<int> pnum;
vector<int> nnum;
int psum, nsum;
int zero, one;

bool comp(int a, int b)
{
    return a > b;
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

        if (tmp > 1)
            pnum.push_back(tmp);
        else if (tmp == 1)
            one++;
        else if (tmp < 0)
            nnum.push_back(tmp);
        else
            zero++;
    }

    sort(pnum.begin(), pnum.end(), comp);
    sort(nnum.begin(), nnum.end());

    for (int i = 0; i + 1 < pnum.size(); i += 2)
    {
        psum += pnum[i] * pnum[i + 1];
    }
    if (pnum.size() % 2 != 0)
        psum += pnum[pnum.size() - 1];

    for (int i = 0; i + 1 < nnum.size(); i += 2)
    {
        nsum += nnum[i] * nnum[i + 1];
    }
    if (nnum.size() % 2 != 0 && zero == 0)
        nsum += nnum[nnum.size() - 1];

    cout << psum + nsum + one;
}