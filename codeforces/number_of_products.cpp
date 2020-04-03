#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    {int i{0}; while(cin >> a[i++]);}

	int sign[] = {-1, 1};
    int pos{0}; int neg{0};
    for(int i = 0; i < a.size(); ++i)
    {
        int prod = 1;
        for(int j = i; j < a.size(); ++j)
        {
            prod *= sign[a[j] > 0];
            if(prod < 0) ++neg;
            else ++pos;
        }
    }

    cout << neg << " " << pos;

    return 0;
}
