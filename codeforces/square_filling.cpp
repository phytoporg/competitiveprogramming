#include <bits/stdc++.h>
using namespace std;

#define M(r, c) ((r)*m + (c))
using matrix = vector<int>;
using tup = pair<int, int>;

int main()
{
    int m, n;
    cin >> n >> m;

    matrix A(m * n, 0);
    matrix B(m * n, 0);

    for (size_t i = 0; i < m*n; ++i)
    {
        cin >> A[i];
    }

    vector<tup> locs;
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < m - 1; ++j)
        {
            if(A[M(i, j)] && A[M(i+1, j)] && A[M(i,j+1)] && A[M(i+1,j+1)])
            {
                B[M(i, j)] = B[M(i+1, j)] = B[M(i,j+1)] = B[M(i+1,j+1)] = 1;
                locs.emplace_back(i, j);
            }
        }
    }

    if (A != B) { cout << -1 << endl; }
    else
    {
        cout << locs.size() << "\n";
        for(size_t i = 0; i < locs.size(); ++i)
        {
            auto [a, b] = locs[i];
            cout << a+1 << " " << b+1 << " \n"[i < locs.size() - 1];
        }
    }

    return 0;
}
