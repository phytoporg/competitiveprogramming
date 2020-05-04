#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

struct state
{
    state(ll w, ll b, ld p)
        : white(w), black(b), prod(p) {}
    ll white;
    ll black;
    ld prod;
};

int main()
{
    ll w, b; cin >> w >> b;

    deque<state> q;
    q.emplace_back(w, b, 1.0L);

    ld sum{0.0L};
    while(!q.empty())
    {
        state curr = q.front();
        q.pop_front();

        if (curr.white > 0)
        {
            // princess turn
            ld winprob(
                curr.prod * (ld)curr.white / (curr.white + curr.black));
            sum += winprob;

            ld loseprob(
                curr.prod * (ld)curr.black / (curr.white + curr.black));
            --curr.black;

            // dragon turn
            if (curr.black > 0)
            {
                ld newprod = 
                    loseprob * 
                    (ld)curr.black / (curr.white + curr.black);
                --curr.black;

                if (curr.black > 0)
                {
                    // Black mouse bails
                    q.emplace_back(
                        curr.white,
                        curr.black - 1,
                        newprod * 
                        (ld)(curr.black) / (ld)(curr.white + curr.black));
                }

                // White mouse bails
                q.emplace_back(
                    curr.white - 1,
                    curr.black,
                    newprod *
                    (ld)(curr.white) / (curr.white + curr.black));
            }
        }
    }

    cout << setprecision(9) << sum << endl;

    return 0;
}

