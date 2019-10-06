#include <bits/stdc++.h>
using namespace std;

struct node
{
    node(char x) : c(x) {}
    char c;
};

struct graph
{
    vector<node>        vertices;
    vector<vector<int>> edges;
};

#define I(r, c) (m*(r) + (c))

static vector<bool> discovered;
int numVisited;
int numToVisit;
static int k, m, n;

void dfs(graph& g, int v)
{
    discovered[v] = true;
    if (++numVisited > (numToVisit - k) && g.vertices[v].c == '.')
    { 
        g.vertices[v].c = 'X'; 
    }

    for(const auto Edge : g.edges[v])
    {
        if(!discovered[Edge])
        {
            dfs(g, Edge);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    graph g;
    discovered.resize(n*m, false);
    {
        int i{0}; char c;
        while(cin >> c)
        {
            g.vertices.emplace_back(c);
        }
    }

    int startingVertex{-1};
    numToVisit = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if (g.vertices[I(i, j)].c == '.' && startingVertex < 0)
            {
                startingVertex = I(i, j);
            }

            numToVisit += g.vertices[I(i, j)].c == '.';

            g.edges.emplace_back();
            auto& adj = g.edges.back();
            if(i > 0   && g.vertices[I(i-1, j)].c == '.') { adj.emplace_back(I(i-1, j)); }
            if(j > 0   && g.vertices[I(i, j-1)].c == '.') { adj.emplace_back(I(i, j-1)); }
            if(i < n-1 && g.vertices[I(i+1, j)].c == '.') { adj.emplace_back(I(i+1, j)); }
            if(j < m-1 && g.vertices[I(i, j+1)].c == '.') { adj.emplace_back(I(i, j+1)); }
        }
    }

    if (startingVertex >= 0)
    {
        numVisited = 0;
        dfs(g, startingVertex);
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << g.vertices[I(i, j)].c;
        }
        cout << "\n";
    }

    return 0;
}
