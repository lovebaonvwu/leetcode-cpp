class DisjointSet
{
public:
    DisjointSet(int n) : size(n)
    {
        parents.resize(size);
        iota(begin(parents), end(parents), 0);

        ranks.resize(size);
        iota(begin(ranks), end(ranks), 0);
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

        if (ranks[px] < ranks[py])
        {
            parents[py] = px;
            ranks[py] = px;
        }
        else
        {
            parents[px] = py;
            ranks[px] = py;
        }
    }

private:
    vector<int> parents;
    vector<int> ranks;
    int size;
};
class Solution
{
public:
    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        DisjointSet ds(c + 1);

        for (auto &conn : connections)
        {
            ds.Union(conn[0], conn[1]);
        }

        unordered_map<int, set<int>> mp;
        for (int i = 1; i <= c; ++i)
        {
            int p = ds.Find(i);
            mp[p].insert(i);
        }

        vector<bool> online(c + 1, true);

        vector<int> ans;

        for (auto &q : queries)
        {
            int op = q[0];
            int node = q[1];

            if (op == 1)
            {
                if (online[node])
                {
                    ans.push_back(node);
                }
                else
                {
                    int p = ds.Find(node);
                    if (!mp[p].empty())
                    {
                        ans.push_back(*mp[p].begin());
                    }
                    else
                    {
                        ans.push_back(-1);
                    }
                }
            }
            else if (op == 2)
            {
                online[node] = false;
                int p = ds.Find(node);
                mp[p].erase(node);
            }
        }

        return ans;
    }
};
// Time: O((C + Q) log C), where C is the number of connections and Q is the number of queries
// Space: O(C)