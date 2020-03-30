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

//
// Taking a BFS-driven approach here.
//

using Cell = std::pair<uint32_t, uint32_t>;
Cell operator+(const Cell& a, const Cell& b)
{
    return Cell(a.first + b.first, a.second + b.second);
}

using Grid = std::vector<std::vector<uint32_t>>;
void DumpGrid(Grid& grid)
{
    const size_t Width = grid.size();
    const size_t Height = grid[0].size();

    for (size_t x = 0; x < Width; ++x)
    {
        for (size_t y = 0; y < Height; ++y)
        {
            std::cout << grid[x][y] << " ";
        }
        std::cout << "\n";
    }
    
    std::cout.flush();
}

void BfsAssign(
    Grid& grid,
    const Cell& startingCell,
    uint32_t i)
{
    std::deque<Cell> q;
    q.push_back(startingCell);

    while(!q.empty())
    {
        static const Cell s_Offsets[] = {
            Cell(-1,-1),
            Cell( 0,-1),
            Cell( 1,-1),
            Cell( 1, 0),
            Cell( 1, 1),
            Cell( 0, 1),
            Cell(-1, 1),
            Cell(-1, 0),
        };

        const Cell Front(q.front());
        q.pop_front();
        for (const auto& Offset : s_Offsets)
        {
            //
            // Check edges
            //
            const Cell TestCell(Front + Offset);
            const auto& [gX, gY] = TestCell;
            const auto& [oX, oY] = Offset;
            if (gX == 0 && oX < 0)
            {
                continue;
            }
            else if (gX == (grid.size() - 1) && oX > 0)
            {
                continue;
            }
            else if (gY == 0 && oY < 0)
            {
                continue;
            }
            else if (gY == (grid[0].size() - 1) && oY > 0)
            {
                continue;
            }
            else if (grid[gX][gY] == 1)
            {
                grid[gX][gY] = i;
                q.push_back(TestCell);
            }
        }
    }
}

int main()
{
    //
    // get input, create grid
    // island index i = 0
    // for each (x,y) in grid
    //   if g(x,y) is 1, bfs setting each to i, ++i
    //   else do nothing
    //

    std::vector<Cell> cells;
    
    uint32_t A; uint32_t B;
    uint32_t x; uint32_t y;

    std::cin >> A >> B;
    while (std::cin >> x >> y) { cells.emplace_back(x, y); }

    Grid grid;
    grid.resize(A);
    for (auto& row : grid) { row.resize(B, 0); }
    for (const auto& Cell : cells) { grid[Cell.first][Cell.second] = 1; }

    uint32_t i{2}; // #Islands
    for (uint32_t x = 0; x < A; ++x)
    {
        for (uint32_t y = 0; y < B; ++y)
        {
            if (grid[x][y] == 1)
            {
                BfsAssign(grid, Cell(x, y), i++);
            }
        }
    }

    DumpGrid(grid);
}

