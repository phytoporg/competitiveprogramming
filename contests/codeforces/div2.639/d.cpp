#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

#define INDEX(r, c) ((c) * n + (r))

int main()
{
    int n, m; cin >> n >> m;

    vector<bool> rows(n, false);
    vector<bool> cols(m, false);

    vector<vector<bool>> visit(n, vector<bool>(m, false));
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            char in; cin >> in;
            bool bw = in == '#';

            visit[r][c] = bw;
            if (bw && rows[r] && (c > 0 && !visit[r][c - 1]))
            {
                cout << "-1\n";
                return 0;
            }

            if (bw && cols[c] && (r > 0 && !visit[r - 1][c]))
            {
                cout << "-1\n";
                return 0;
            }

            rows[r] = (rows[r] | bw);
            cols[c] = (cols[c] | bw);
        }
    }

    vector<bool> fullRows(n, false);
    vector<bool> fullCols(m, false);
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            if (!visit[r][c] && !cols[c] && !rows[r])
            {
                fullRows[r] = true;
                fullCols[c] = true;
            }

            fullRows[r] = (fullRows[r] | rows[r]);
            fullCols[c] = (fullCols[c] | cols[c]);
        }
    }

    auto good = [n, m, &visit](int r, int c)
    {
        return r >= 0 && r < n && c >= 0 && c < m;
    };

    using pp = pair<int, int>;
    pp offsets[] = 
    {
        {-1,  0},
        { 0, -1},
        { 0,  1},
        { 1,  0},
    };

    int north{0};
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            if (!fullRows[r] || !fullCols[c]) 
            {
                cout << "-1\n";
                return 0;
            }

            if (!visit[r][c]) { continue; }

            ++north;
            queue<pp> q;
            q.push(make_pair(r, c));
            while(!q.empty())
            {
                auto [cr, cc] = q.front();
                q.pop();

                visit[cr][cc] = false;
                for (auto& [dr, dc] : offsets)
                {
                    int nr = cr + dr; int nc = cc + dc;
                    if (good(nr, nc) && visit[nr][nc])
                    {
                        q.push(make_pair(nr, nc));
                    }
                }
            }
        }
    }

    cout << north << endl;

    return 0;
}

