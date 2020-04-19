#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n; cin >> n;

    vector<int> negatives;
    vector<int> positives;
    vector<int> zeros;
    for (int i = 0; i < n; ++i)
    {
        int ai; cin >> ai;
        if (ai < 0) { negatives.push_back(ai); }
        else if (ai > 0) { positives.push_back(ai); }
        else { zeros.push_back(ai); }
    }

    cout << "1 " << negatives.back() << "\n";
    negatives.pop_back();

    if (positives.size() == 0)
    {
        int len(negatives.size());
        cout << "2 " << negatives[len - 1] << ' ' << negatives[len - 2] << "\n";
        negatives.resize(len - 2);
    }
    else
    {
        cout << "1 " << positives.back() << "\n";
        positives.pop_back();
    }

    int remaining(negatives.size() + positives.size() + zeros.size());
    cout << remaining << ' ';
    for (int& i : negatives) { cout << i << ' '; }
    for (int& i : positives) { cout << i << ' '; }
    for (int& i : zeros) { cout << i << " \n"[&i == &zeros.back()]; }

    return 0;
};
