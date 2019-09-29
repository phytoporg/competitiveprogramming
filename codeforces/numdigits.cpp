#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 2147447412;
    //int a = 123454321;
    unsigned numDigits{0};

    int x = a;
    while(x > 0)
    {
        x /= 10;
        ++numDigits;
    }

    cout << numDigits << endl;
    cout << pow(10, numDigits) << endl << endl;; 

    unsigned lowBase = 10;
    unsigned highBase = pow(10, numDigits - 1);
    while(highBase > (lowBase - 1))
    {
        auto lo = a % lowBase;
        auto hi = a / highBase;

        cout << lo << " " << hi << endl;

        a %= highBase;
        a /= 10;
        highBase /= 100;

        //cout << lowBase << " " << highBase << endl;
    }

    return 0;
}
