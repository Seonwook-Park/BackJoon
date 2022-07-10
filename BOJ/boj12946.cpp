#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
char board[51][51];
int visit[51][51];
int dx[] = {1, 1, -1, -1, 0, 0};
int dy[] = {0, -1, 0, 1, -1, 1};
int ans;

void dfs(int x, int y, int c)
{
    visit[x][y] = c;
    ans = max(ans, 1);

    for (int i = 0; i < 6; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (board[nx][ny] != 'X')
            continue;
        if (visit[nx][ny] == -1)
            dfs(nx, ny, 1 - c);

        ans = max(ans, 2);
        if (visit[nx][ny] == c)
            ans = 3;
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    memset(visit, -1, sizeof(visit));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'X' && visit[i][j] == -1)
                dfs(i, j, 0);
        }
    }

    cout << ans;
}