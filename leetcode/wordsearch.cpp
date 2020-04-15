#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using loc = pair<int, int>;
bool adjacent(loc& a, loc& b)
{
    int dx = a.first - b.first;
    int dy = a.second - b.second;

    return (dx * dx) + (dy * dy) == 1;
}

bool bt(
    unordered_map<char, vector<loc>>& charmap,
    vector<loc>& state,
    int i,
    string& word,
    bitset<200 * 200 + 1>& visited,
    int m, int n)
{
    int len(word.length());
    if (i == len)
    {
        return true;
    }
    else
    {
        bool found{false};
        if (!charmap.count(word[i])) { return false; }
        for (auto& next : charmap[word[i]])
        {
            auto& [col, row] = next;
            int idx = col + row * m;
            if (!visited[idx] && 
                    (state.empty() || adjacent(next, state.back())))
            {
                visited[idx] = true;
                state.push_back(next);
                found |= bt(charmap, state, i + 1, word, visited, m, n);
                state.pop_back();
                visited[idx] = false;
            }
        }

        return found;
    }
}

bool exist(vector<vector<char>>& board, string word)
{
    unordered_map<char, vector<loc>> charmap;
    int m(board.size());
    int n(board.front().size());
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!charmap.count(board[i][j]))
            {
                charmap[board[i][j]] = vector<loc>{ make_pair(i, j) };
            }
            else
            {
                charmap[board[i][j]].emplace_back(i, j);
            }
        }
    }

    bitset<200 * 200 + 1> visited;
    vector<loc> state;
    return bt(charmap, state, 0, word, visited, m, n);
}

int main()
{
    vector<vector<char>> board
    {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };

    cout << "SEE? " << (exist(board, "SEE") ? "YES" : "NO") << endl;
    cout << "ABCCED? " << (exist(board, "ABCCED") ? "YES" : "NO") << endl;
    cout << "ABCB? " << (exist(board, "ABCB") ? "YES" : "NO") << endl;

    return 0;
}

