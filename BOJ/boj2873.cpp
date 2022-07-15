#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define MAX_NUM 1111

using namespace std;

int r, c;
int joy[1010][1010];
int minVal = MAX_NUM;
pair<int, int> minpos;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    vector<int> v(r);
    vector<int> s(c);

    if (r % 2 != 0) // r이 홀수
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cin >> joy[i][j];
        }

        for (int i = 0; i < r; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < c - 1; j++)
                {
                    cout << "R";
                }
            }
            else
            {
                for (int j = 0; j < c - 1; j++)
                {
                    cout << "L";
                }
            }

            if (i != r - 1)
                cout << "D";
        }
    }
    else if (c % 2 != 0)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cin >> joy[i][j];
        }

        for (int i = 0; i < c; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < r - 1; j++)
                {
                    cout << "D";
                }
            }
            else
            {
                for (int j = 0; j < r - 1; j++)
                {
                    cout << "U";
                }
            }

            if (i != c - 1)
                cout << "R";
        }
    }
    else
    {

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> joy[i][j];

                if ((i + j) % 2 != 0 && joy[i][j] < minVal)
                {
                    minVal = joy[i][j];
                    minpos = make_pair(i, j);
                }
            }
        }

        int xpos = minpos.first % 2 == 0 ? minpos.first : minpos.first - 1;
        int ypos = minpos.second;

        for (int i = 0; i < xpos; i++)
        {

            if (i % 2 == 0)
            {
                for (int j = 0; j < c - 1; j++)
                    cout << "R";
            }
            else
            {
                for (int j = 0; j < c - 1; j++)
                    cout << "L";
            }

            cout << "D";
        }

        int q = 1;

        for (int i = 0; i < c - 1; i++)
        {

            if (i == ypos)
            {
                cout << "R";
                continue;
            }

            if (q == 1)
            {
                cout << "D";
                q = 1 - q;
            }
            else if (q == 0)
            {
                cout << "U";
                q = 1 - q;
            }

            cout << "R";
        }

        if (ypos != c - 1)
            cout << "D";

        for (int i = xpos + 2; i < r; i++)
        {
            cout << "D";

            if (i % 2 == 0)
            {
                for (int j = 0; j < c - 1; j++)
                    cout << "L";
            }
            else
            {
                for (int j = 0; j < c - 1; j++)
                    cout << "R";
            }
        }
    }
}
