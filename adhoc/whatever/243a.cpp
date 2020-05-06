#include <bits/stdc++.h>
 
using namespace std;
 
const int BITLEN = 20;
const int MAXN = 100100;
 
int a[MAXN];
bool mark[1 << BITLEN];
int last[BITLEN];
multiset<int> ms;
 
int main() {
  int n;
 
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
	scanf("%d", &a[i]);
	mark[a[i]] = true;
  }
  for (int i = 0; i < BITLEN; ++i) {
	last[i] = n;
	ms.insert(last[i]);
  }
 
  for (int i = n - 1; i >= 0; --i) {
	for (int j = 0; j < BITLEN; ++j) {
	  if (a[i] & (1 << j)) {
		ms.erase(ms.find(last[j]));
		last[j] = i;
		ms.insert(last[j]);
	  }
	}

    for (auto k : ms) { cout << k << ' '; }
    cout << endl;
 
	int m = 0;
	set<int> s(ms.begin(), ms.end());
	s.erase(n);
	for (int j: s) {
	  m |= a[j];
	  mark[m] = true;
	}
  }
  printf("%d\n", count(mark, mark + (1 << BITLEN), true));
 
  return 0;
}

