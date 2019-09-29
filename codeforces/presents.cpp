#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin >> n;
	vector<int> p; p.reserve(n);
	int p_i;
	while(cin >> p_i) { p.emplace_back(p_i); }
	
	vector<int> output(p.size());
	for (size_t i = 0; i < p.size(); ++i) { 
		output[p[i] - 1] = i + 1;
	}

	for (int i : output) { cout << i << " "; }
	return 0;
}
