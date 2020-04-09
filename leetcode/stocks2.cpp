#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ull = unsigned long long;
int maxProfit(vector<int>& prices) 
{
	int n(prices.size());
	if (n <= 1) { return 0; }
	
	int bi = -1;
	ull profit{0};
	ull sum{0};
	for (int i = 1; i < n; ++i)
	{
		int delta = prices[i-1] - prices[i];
		if (delta < 0)
		{
			sum -= delta;
		}
		else
		{
			profit += sum;
			sum = 0;
		}
	}
	
	return profit + sum;
}

int main()
{
	////vector<int> prices{7,1,5,3,6,4};
	vector<int> prices;
    int price;
    while (cin >> price) { prices.push_back(price); }

    cout << maxProfit(prices) << endl;

	return 0;
}
