#include <bits/stdc++.h>
using namespace std;

//
// Combinations:
//  * and *
//  * and +
//  + and +
//  + and *
//

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> v{
        a * b * c, 
        a * (b + c), 
        a * b + c, 
        a + b + c,
        (a + b) * c,
        a + b * c,
    };

    cout << *max_element(begin(v), end(v));

    return 0;
}
