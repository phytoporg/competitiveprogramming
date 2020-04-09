#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

void bt(
	vector<vector<int>>& combos,
	vector<int>& candidates,
	vector<int>& state,
	int sum, 
	size_t i, 
	int target)
{
	if (sum == target)
	{
		combos.push_back(state);
	}
	else
	{
		for (size_t n = 0; n < candidates.size(); ++n)
		{
			int value = candidates[n];
            if (value < 0) return;
			if (sum + value <= target && 
                (state.empty() || (state.back() <= value)))
			{
				state.push_back(value);
				bt(combos, candidates, state, sum + value, i + 1, target);
				state.pop_back();
			}
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> combos;
	vector<int> state;
    sort(begin(candidates), end(candidates));
	bt(combos, candidates, state, 0, 0, target);
	
	return combos;
}

int main()
{
	vector<int> v;
    int n;
    while(cin >> n) { v.push_back(n); };

    int target = v.back();
    v.pop_back();

    auto combos = combinationSum(v, target);
    for (auto& combo : combos)
    {
        for (int& value : combo)
        {
            cout << value << " \n"[&value == &combo.back()];
        }
    }

    return 0;
}
