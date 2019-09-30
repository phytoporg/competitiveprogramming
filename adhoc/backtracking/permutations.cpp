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

void printPermutations(vector<int>& data, int k)
{
    if (k == data.size())
    {
        printVector(data);
    }
    else
    {
        for(int i = k; i < data.size(); ++i)
        {
            if (i != k) swap(data[i], data[k]);
            printPermutations(data, k + 1);
            if (i != k) swap(data[i], data[k]);
        }
    }
}

int main()
{
    int n; cin >> n;
    vector<int> data(n);
    int i{0};
    while(cin >> data[i++]);
    printPermutations(data, 0);

    return 0;
}
