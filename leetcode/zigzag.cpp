#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

#define up (true)
#define down (!up)

string convert(string s, int r) {
	if (!r) { return s; }
	
	int n(s.size());
	int i{0};
	int ri{0};
	
	string t(s);
	while(ri < r)
	{
		bool d = up;
		for(int ci = ri; ci < n && i < n;)
		{
			t[i++] = s[ci];
			
			if (ri == 0) { d = down; }
            else if (ri == r - 1) { d = up; }
			else { d = !d; }
			
            int P = ((d == down) ? (2 * (r - 1 - ri)) : (2 * ri));
			ci += P;
		}
		++ri;
	}
	
	return t;
}

int main()
{
    string s;
    cin >> s;

    int r;
    cin >> r;

    cout << convert(s, r) << endl;
    return 0;
}

