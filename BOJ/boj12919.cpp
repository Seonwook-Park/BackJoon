#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string s, t;
string reverse_t;

void changeString(string str)
{

    if (str == s)
    {
        cout << 1;
        exit(0);
    }

    if (str.length() <= s.length())
        return;

    if (str[str.size() - 1] == 'A' && str[0] == 'A') //앞뒤 다 A : 뒤A빼기
    {
        string tmp = str.substr(0, str.size() - 1);
        changeString(tmp);
    }
    else if (str[str.size() - 1] == 'A' && str[0] == 'B') // 앞B뒤A : 둘다
    {
        string tmp1 = str.substr(0, str.size() - 1);
        changeString(tmp1);

        string tmp2 = str.substr(1, str.size() - 1);
        reverse(tmp2.begin(), tmp2.end());
        changeString(tmp2);
    }
    else if (str[str.size() - 1] == 'B' && str[0] == 'B') //앞뒤 다 B : 앞B빼고, 뒤집기
    {
        string tmp = str.substr(1, str.size() - 1);
        reverse(tmp.begin(), tmp.end());
        changeString(tmp);
    }
    else if (str[str.size() - 1] == 'B' && str[0] == 'A') //앞A뒤B : 불가능
        return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;

    string reverse_t = t;
    reverse(reverse_t.begin(), reverse_t.end());

    if (t.find(s) != string::npos || reverse_t.find(s) != string::npos)
        changeString(t);

    cout << 0;
}