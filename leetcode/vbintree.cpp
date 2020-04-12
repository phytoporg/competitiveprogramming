//
// This is written to paste into leetcode, not to run, hence no entry point.
//
// Things to look over: iterative tree traversal and single-pass construction
// of verticalTraversal() output.
//
using elem = pair<int, int>;

void 
helper(
    TreeNode* root,
    int x,
    int& minL,
    int& maxR,
    int& depth,
    unordered_map<int, elem>& m
    )
{
    if (!root) { return; }

    helper(root->left, x - 1, minL, maxR, depth + 1, m);

    minL = min(minL, x);
    maxR = max(maxR, x);

    m[root->val] = make_pair(depth, x);

    helper(root->right, x + 1, minL, maxR, depth + 1, m);
}

vector<vector<int>> verticalTraversal(TreeNode* root)
{
    int minL{0}; int maxR{0};
    int depth{0};
    int x{0};

    unordered_map<int, elem> m;
    helper(root, x, minL, maxR, depth, m);

    vector<vector<int>> output(maxR - minL + 1);

    for (auto& [val, p] : m)
    {
        auto [IGNORE, x] = p;
        int index = x - minL;
        auto& v = output[index];
        auto it = lower_bound(begin(v), end(v), val, [&m](int a, int b)
            {
                return make_tuple(m[a].first, m[a].second, a) < 
                       make_tuple(m[b].first, m[b].second, b);
            });
        v.insert(it, val);
    }

    return output;
}

