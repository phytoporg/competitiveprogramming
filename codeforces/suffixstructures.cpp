#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

int freqt[26] = {};
int freqs[26] = {};
int main()
{
    // s -> t
    // automaton : add/insert characters
    // array     : swap characters
    // both      : insert & swap characters
    // need tree : 
    
    // automaton: len(s) > len(t) and t in s
    // array: len(s) == len(t) and t intersects s, not in s
    // both: len(s) > len(t) and t intersects s and t not in s
    // else tree

    string s, t;
    cin >> s >> t;

    int slen(s.length());
    int tlen(t.length());
    for (int i = 0; i < slen; ++i) { freqs[s[i] - 'a']++; }
    for (int i = 0; i < tlen; ++i) { freqt[t[i] - 'a']++; }

    bool intersects{true};
    for (int i = 0; i < 26; ++i) 
    {
        if (freqt[i] > freqs[i]) { intersects = false; break; }
    }

    if (!intersects)
    {
        cout << "need tree";
    }
    else
    {
        bool automaton = { slen > tlen };

        int ti{0}; int si{0};
        while(ti < tlen && si < slen)
        {
            if (t[ti] == s[si])    { ++ti; }

            ++si;
        }
        bool array{ti < tlen};

        if (automaton && array)
        {
            cout << "both";
        }
        else if (automaton)
        {
            cout << "automaton";
        }
        else if (array)
        {
            cout << "array";
        }
    }

    cout << endl;

    return 0;
};
