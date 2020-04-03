#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main(int argc, char** argv)
{
    srand(atoi(argv[1]));
    int n = rand() % 100 + 2;

    vector<int> a(n);
    for (auto& i : a)
    {
        cout << rand() % 1000 + 1;
        if (&i != &a.back()) { cout << ' '; }
    }
    
    return 0;
}

