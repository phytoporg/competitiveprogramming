#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main(int argc, char** argv)
{
    int seed{atoi(argv[1])};
    srand(seed);

    int len = rand() % 100 + 1;
    vector<int> values(len);
    for (int& v : values) 
    { 
        v = rand() % 200 - 100;
    }

    cout << "1\n" << len << "\n";
    for (int& v : values) { cout << v << ' '; }

    return 0;
}

