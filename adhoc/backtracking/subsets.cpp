#include <bits/stdc++.h>
using namespace std;

//
// Codeforces style input:
// n
// a_1 ... a_n
//
// a_n <-- int
//

void printVector(const vector<int>& a)
{
    cout << "{";
    for(auto i : a)
    {
        cout << " " << i;
    }
    cout << " }\n";
}

void printSubsets(vector<int>& a, const vector<int>& data, int k)
{
    if (k == data.size())
    {
        printVector(a);
    }
    else
    {
        printSubsets(a, data, k + 1);

        a.push_back(data[k]);
        printSubsets(a, data, k + 1);
        a.pop_back();
    }
}

int main()
{
    int n; cin >> n;
    vector<int> data(n);
    int i{0};
    while(cin >> data[i++]);

    vector<int> a;
    printSubsets(a, data, 0);

    return 0;
}
