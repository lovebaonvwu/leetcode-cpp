class DisjointSet
{
public:
    DisjointSet(int n) : size(n), count(n)
    {
        parents.resize(size);
        ranks.resize(size);

        iota(begin(parents), end(parents), 0);
    }

    int Find(int x)
    {
        if (parents[x] != x)
        {
            parents[x] = Find(parents[x]);
        }

        return parents[x];
    }

    void Union(int x, int y)
    {
        int px = Find(x);
        int py = Find(y);

        if (px == py)
        {
            return;
        }

        if (ranks[px] > ranks[py])
        {
            parents[py] = px;
            ++ranks[px];
        }
        else
        {
            parents[px] = py;
            ++ranks[py];
        }

        --count;
    }

    int Count()
    {
        return count;
    }

private:
    vector<int> parents;
    vector<int> ranks;
    int size;
    int count;
};

class Solution
{
public:
    int minCost(int n, vector<vector<int>> &edges, int k)
    {
        sort(begin(edges), end(edges), [](auto &a, auto &b)
             { return a[2] < b[2]; });

        DisjointSet ds(n);

        int ans = 0;
        for (auto &e : edges)
        {
            int x = e[0];
            int y = e[1];
            int w = e[2];

            if (ds.Count() <= k)
            {
                break;
            }

            ds.Union(x, y);
            ans = max(ans, w);
        }

        return ans;
    }
};
// Time: O(E log E)
// Space: O(V)
// where E is the number of edges, V is the number of vertices