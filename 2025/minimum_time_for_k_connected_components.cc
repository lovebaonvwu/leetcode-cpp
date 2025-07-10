class DisjointSet
{
public:
    DisjointSet(int n) : size(n), count(n)
    {
        parents.resize(n);
        iota(begin(parents), end(parents), 0);

        ranks.resize(n);
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

        if (ranks[px] >= ranks[py])
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
    int minTime(int n, vector<vector<int>> &edges, int k)
    {
        sort(begin(edges), end(edges), [](auto &a, auto &b)
             { return a[2] > b[2]; });

        DisjointSet ds(n);

        for (auto &e : edges)
        {
            int x = e[0];
            int y = e[1];
            int t = e[2];

            ds.Union(x, y);

            if (ds.Count() < k)
            {
                return t;
            }
        }

        return 0;
    }
};
// Time: O(E + E * log(E))
// Space: O(n)