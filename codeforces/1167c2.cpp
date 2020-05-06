#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int find_set(int x, vector<int>& parent)
{
    if (parent[x] == x)
    {
        return x;
    }
    
    return parent[x] = find_set(parent[x], parent);
}

void set_union(int x, int y, vector<int>& parent, vector<int>& size)
{
    int a = find_set(x, parent);
    int b = find_set(y, parent);

    if (a != b)
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }

        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    int n, m; cin >> n >> m;

    vector<int> parent(n);
    iota(begin(parent), end(parent), 0);

    vector<int> size(n, 1);
    for (int mi = 0; mi < m; ++mi)
    {
        int count; cin >> count;
        vector<int> group(count);
        for(int& gi : group) { cin >> gi; --gi; }

        for (int ni = 1; ni < count; ++ni)
        {
            set_union(group[ni], group[ni - 1], parent, size);
        }
    }

    for (int ni = 0; ni < n; ++ni)
    {
        cout << size[find_set(ni, parent)] << ' ';
    }
    cout << endl;

    return 0;
}

