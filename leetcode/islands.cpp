#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int numIslands(vector<vector<char>>& grid) {
	int islands{0};
	if (grid.empty()) { return islands; }
	
	map<int, int> eq;
	
	int m(grid.size());
	int n(grid.front().size());

    vector<vector<int>> grid2(m, vector<int>(n, 0));
    for (int y = 0; y < m; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            grid2[y][x] = grid[y][x] == '0' ? 0 : -1;
            cout << grid[y][x];
        }
        cout << endl;
    }
    cout << endl;

	for (int y = 0; y < m; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			if (grid2[y][x] < 0)
			{
				char left = (x - 1 >= 0) ? grid2[y][x - 1] : 0;
				char up   = (y - 1 >= 0) ? grid2[y - 1][x] : 0;
				
				if (left == 0 && up == 0) 
				{
					grid2[y][x] = ++islands; eq[islands] = islands; 
				}
				else if (left == 0 && up   > 0) { grid2[y][x] = up;   }
				else if (up   == 0 && left > 0) { grid2[y][x] = left; }
				else if (up != left) 
				{
					grid2[y][x] = min(up, left);
					eq[max(up, left)] = grid2[y][x];
				}
				else if (up == left) { grid2[y][x] = left; }
			}
		}
	}

    for (int y = 0; y < m; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            cout << char(grid2[y][x] + 'A');
        }
		cout << endl;
    }

	for (auto& [a, b] : eq)
	{
		islands -= (a != b);
	}
	
	return islands;
}

int main()
{
    vector<vector<char>> land = 
    /*{
        {'1','1','1','1','1','1','1'},
        {'0','0','0','0','0','0','1'},
        {'1','1','1','1','1','0','1'},
        {'1','0','0','0','1','0','1'},
        {'1','0','1','0','1','0','1'},
        {'1','0','1','1','1','0','1'},
        {'1','1','1','1','1','1','1'},
    };*/
    /*{{'1','0','0','1','1','1','0','1','1','0','0','0','0','0','0','0','0','0','0','0'},
     {'1','0','0','1','1','0','0','1','0','0','0','1','0','1','0','1','0','0','1','0'},
     {'0','0','0','1','1','1','1','0','1','0','1','1','0','0','0','0','1','0','1','0'},
     {'0','0','0','1','1','0','0','1','0','0','0','1','1','1','0','0','1','0','0','1'},
     {'0','0','0','0','0','0','0','1','1','1','0','0','0','0','0','0','0','0','0','0'},
     {'1','0','0','0','0','1','0','1','0','1','1','0','0','0','0','0','0','1','0','1'},
     {'0','0','0','1','0','0','0','1','0','1','0','1','0','1','0','1','0','1','0','1'},
     {'0','0','0','1','0','1','0','0','1','1','0','1','0','1','1','0','1','1','1','0'},
     {'0','0','0','0','1','0','0','1','1','0','0','0','0','1','0','0','0','1','0','1'},
     {'0','0','1','0','0','1','0','0','0','0','0','1','0','0','1','0','0','0','1','0'},
     {'1','0','0','1','0','0','0','0','0','0','0','1','0','0','1','0','1','0','1','0'},
     {'0','1','0','0','0','1','0','1','0','1','1','0','1','1','1','0','1','1','0','0'},
     {'1','1','0','1','0','0','0','0','1','0','0','0','0','0','0','1','0','0','0','1'},
     {'0','1','0','0','1','1','1','0','0','0','1','1','1','1','1','0','1','0','0','0'},
     {'0','0','1','1','1','0','0','0','1','1','0','0','0','1','0','1','0','0','0','0'},
     {'1','0','0','1','0','1','0','0','0','0','1','0','0','0','1','0','1','0','1','1'},
     {'1','0','1','0','0','0','0','0','0','1','0','0','0','1','0','1','0','0','0','0'},
     {'0','1','1','0','0','0','1','1','1','0','1','0','1','0','1','1','1','1','0','0'},
     {'0','1','0','0','0','0','1','1','0','0','1','0','1','0','0','1','0','0','1','1'},
     {'0','0','0','0','0','0','1','1','1','1','0','1','0','0','0','1','1','0','0','0'}};*/

        
	{{'1','0','1','1','0','0','1','0','1','1','1','1','0','1','0','1','1','1','1','0'},
	 {'0','1','0','0','1','0','1','0','1','1','1','1','1','1','0','1','1','0','1','1'},
	 {'1','0','0','1','0','1','0','1','0','1','1','0','1','1','1','0','0','1','1','0'},
	 {'0','1','1','0','0','1','1','0','1','1','1','1','0','0','1','0','0','0','1','1'},
	 {'1','1','0','1','0','0','1','0','0','0','1','0','1','0','1','1','1','0','1','1'},
	 {'0','0','0','0','1','0','1','1','0','0','1','0','0','1','0','1','1','1','1','0'},
	 {'1','0','1','1','1','1','0','1','1','0','1','1','0','1','1','1','0','0','1','0'},
	 {'0','1','1','0','0','0','1','0','0','1','0','1','1','1','0','0','1','1','0','1'},
	 {'0','0','0','0','1','1','0','1','0','0','1','1','0','1','0','0','1','0','1','0'},
	 {'0','0','1','1','1','0','1','0','1','0','1','1','1','0','1','1','1','1','1','0'},
	 {'1','0','1','0','1','1','1','0','1','1','1','0','1','0','1','0','1','0','1','1'},
	 {'0','0','1','1','1','1','0','1','1','1','0','1','0','0','0','1','1','1','0','1'},
	 {'1','1','1','0','0','0','0','0','1','1','0','1','1','1','0','1','1','1','1','0'},
	 {'0','0','1','1','1','0','0','1','0','0','1','1','1','1','1','1','0','1','1','0'},
	 {'0','0','0','1','1','0','0','0','0','1','1','0','1','0','0','1','1','1','1','1'},
	 {'0','1','1','1','0','1','0','0','1','1','1','1','1','0','1','1','1','0','0','1'},
	 {'0','0','0','0','1','1','1','1','0','0','0','0','1','0','0','0','0','1','1','0'},
	 {'1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1','1','1'},
	 {'0','1','0','0','1','0','0','1','1','1','1','1','1','0','1','0','1','1','1','1'},
	 {'0','0','1','1','1','1','1','0','0','0','1','1','1','1','1','1','0','1','1','0'}};
 
    cout << numIslands(land) << endl;

    return 0;
}

