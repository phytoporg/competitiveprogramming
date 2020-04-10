#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

vector<int> spiralOrder(vector<vector<int>> matrix)
{
    if (matrix.empty()) { return vector<int>{}; }

	int rows(matrix.size());
	int cols(matrix.front().size());
	
	int  c{0}; int  r{0};
	int dc{1}; int dr{0};
	int lc{0}; int lr{0};
	int total{rows * cols};
	int visited{0};
	
	vector<int> output(total);
	while(visited < total)
	{
		while(c >= lc && c < cols && r >= lr && r < rows)
		{
			output[visited] = matrix[r][c];
			c += dc; r += dr;
			++visited;
		}

		if      (c < lc)    { dc = 0; dr = -1; --rows; }
		else if (c >= cols) { dc = 0; dr =  1; ++lr;   }
		else if (r < lr)    { dr = 0; dc =  1; ++lc;   }
		else if (r >= rows) { dr = 0; dc = -1; --cols; }

		c = max(lc, c); c = min(c, cols - 1);
		r = max(lr, r); r = min(r, rows - 1);
	}
	
	return output;
}

int main()
{
	vector<vector<int>> m1 {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

	vector<vector<int>> m2 {
        {1, 2,  3,  4 },
        {5, 6,  7,  8 },
        {9, 10, 11, 12},
    };

    vector<vector<int>> m3;

    auto v = spiralOrder(m1);

    for (int& vi : v) { cout << vi << ' '; }

    return 0;
}
