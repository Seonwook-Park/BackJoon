#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

string str;
vector<int> n;
vector<char> p;
int pre, post;
bool minusexist;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;

    int l = str.size();

    for (int i = 0; i < l; i++)
    {
        string num = "";

        while (i < l && str[i] >= 48 && str[i] <= 71) //숫자이면
        {
            num += str[i];
            i++;
        }

        n.push_back(stoi(num));

        if (i < l)
        {
            p.push_back(str[i]);
        }
    }

    pre = n[0];

    for (int i = 0; i < n.size() - 1; i++)
    {
        if (!minusexist && p[i] == '+')
        {
            pre += n[i + 1];
            minusexist = false;
        }
        else if (minusexist && p[i] == '+')
        {
            post += n[i + 1];
            minusexist = true;
        }
        else if (!minusexist && p[i] == '-')
        {
            post += n[i + 1];
            minusexist = true;
        }
        else if (minusexist && p[i] == '-')
        {
            pre -= post;
            post = n[i + 1];
            minusexist = true;
        }
    }

    cout << pre - post;
}
