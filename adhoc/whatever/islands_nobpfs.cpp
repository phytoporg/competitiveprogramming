#include <bits/stdc++.h>
using namespace std;

//
// Input: 
// A, B
// x1,y1
// x2,y2
// ...
// xn,yn
//
// On a 2D grid, all values are zero unless they appear in the (x, y) coordinate
// set specified in the input, in which case they are equal to one.
//
// Count the number of "islands" of nonzero values on the grid, where 
// connectivity is 8-way (as opposed to 4-way).
//

using Grid = std::vector<std::vector<uint32_t>>;
void DumpGrid(Grid& grid)
{
    const size_t Width = grid.size();
    const size_t Height = grid[0].size();

    for (size_t x = 1; x < Width - 1; ++x)
    {
        for (size_t y = 1; y < Height - 1; ++y)
        {
            std::cout << grid[x][y] << " ";
        }
        std::cout << "\n";
    }
    
    std::cout.flush();
}

int main()
{
    uint32_t A, B;
    cin >> A >> B;
    
    using Cell = pair<uint32_t, uint32_t>;
    vector<Cell> cells;
    uint32_t x, y;
    while(cin >> x >> y) { cells.emplace_back(x, y); }

    Grid grid;
    grid.resize(A + 2);
    for (auto& col  : grid) { col.resize(B + 2, 0); }
    for (auto& cell : cells) { const auto [X, Y] = cell; grid[X+1][Y+1] = 1; }

    uint32_t i = 2;
    vector<uint32_t> referenceMap;
    for (size_t x = 1; x <= A; ++x)
    {
        for (size_t y = 1; y <= B; ++y)
        {
            if(grid[x][y] == 1)
            {
                const auto Above = grid[x-1][y];
                const auto Behind  = grid[x][y-1];

                if (Above == 0 && Behind == 0)
                {
                    grid[x][y] = i;
                    if (referenceMap.size() <= i) 
                    { 
                        referenceMap.resize(i + 1, 0); 
                    }
                    referenceMap[i] = i;
                    ++i;
                }
                else if (Above > 1 && Behind == 0)
                {
                    grid[x][y] = Above;
                }
                else if (Above == 0 && Behind > 1)
                {
                    grid[x][y] = Behind;
                }
                else if (Above > 1 && Behind > 1 && Above == Behind)
                {
                    grid[x][y] = Above;
                }
                else if (Above > 1 && Behind > 1 && Above != Behind)
                {
                    grid[x][y] = Above > Behind ? Behind : Above;
                    if (Above > Behind)
                    {
                        assert(Above < referenceMap.size());
                        referenceMap[Above] = Behind;
                        grid[x][y] = Behind;
                    }
                    else
                    {
                        assert(Behind < referenceMap.size());
                        referenceMap[Behind] = Above;
                        grid[x][y] = Above;
                    }
                }
            }
        }
    }

    uint32_t numIslands{0};
    for (size_t i = 2; i < referenceMap.size(); ++i)
    {
        if (referenceMap[i] == i) { ++numIslands; }
    }

    DumpGrid(grid);

    cout << numIslands << std::endl;

    return 0;
}

