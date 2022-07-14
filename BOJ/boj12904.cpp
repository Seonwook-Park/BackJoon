#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string s, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;

    while (true)
    {

        if (s == t)
        {
            cout << 1;
            return 0;
        }
        if (s.length() == t.length())
            break;

        if (t[t.length() - 1] == 'A')
        {
            t = t.substr(0, t.length() - 1);
        }
        else if (t[t.length() - 1] == 'B')
        {
            t = t.substr(0, t.length() - 1);
            reverse(t.begin(), t.end());
        }
    }

    cout << 0;
}
