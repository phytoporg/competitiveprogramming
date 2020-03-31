#include <bits/stdc++.h>
using namespace std;

string input = "babad";

string longestPalindromeString(string s)
{
	if (s.empty()) { return s; }
	
	size_t bestLen{1};
	size_t bestLeft{0};
	
	const size_t n{s.size()};
	
	//
	// Odd-len palindromes
	// 
	for (size_t mid = 0; mid < n; ++mid)
	{
		for (size_t r = 0; mid - r >= 0 && mid + r < n; ++r)
		{
			if (s[mid - r] != s[mid + r]) { break; }
			const size_t len{r * 2 + 1};
			if (len > bestLen)
			{
				bestLen = len;
				bestLeft = mid - r;
			}
		}
	}
	
	//
	// Even-len palindromes
	//
	for (size_t mid = 0; mid < n; ++mid)
	{
		for (size_t r = 1; mid - r + 1 >= 0 && mid + r < n; ++r)
		{
			if (s[mid - r + 1] != s[mid + r]) { break; }
			const size_t len{r * 2};
			if (len > bestLen)
			{
				bestLen = len;
				bestLeft = mid - r + 1;
			}
		}
	}
	
	return string(s, bestLeft, bestLen);
}

int main()
{
    cout << longestPalindromeString(input) << endl;
    return 0;
}
