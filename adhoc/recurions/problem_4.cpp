#include <bits/stdc++.h>
using namespace std;

void printPolynomial(int i, int n)
{
    int exp{i};

    if (exp == 0)
    {
        cout << "1";
    }
    else if (exp == 1)
    {
        cout << "x";
    }
    else 
    {
        cout << "x^" << i;
    }

    if (i < (n - 1))
    {
        cout << " + ";
        printPolynomial(i + 1, n);
    }
}

int main()
{
    int n; cin >> n;

    printPolynomial(0, n);
    return 0;
}
