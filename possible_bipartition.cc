class UnionFind
{
private:
    vector<int> parent, rank;
public:
    UnionFind(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }

        rank.resize(n);
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void union_set(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if (px == py)
        {
            return;
        }

        if (rank[px] > rank[py])
        {
            parent[py] = px;
        }
        else if (rank[py] > rank[px])
        {
            parent[px] = py;
        }
        else
        {
            parent[py] = px;
            ++rank[px];
        }
    }
};

class Solution 
{
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<vector<int>> g(n + 1);
        for (auto& d : dislikes)
        {
            g[d[0]].push_back(d[1]);
            g[d[1]].push_back(d[0]);
        }

        UnionFind uf(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            for (auto& neighbor : g[i])
            {
                if (uf.find(i) == uf.find(neighbor))
                {
                    return false;
                }

                uf.union_set(g[i][0], neighbor);
            }
        }

        return true;
    }
};
// Runtime 474 ms
// Memory 64.7 MB
// 2022.12.21 at 奥盛大厦

class Solution 
{
    bool bfs(int node, vector<vector<int>>& g, vector<int>& color)
    {
        queue<int> q;
        q.push(node);
        color[node] = 0;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (auto& neighbor : g[cur])
            {
                if (color[neighbor] == color[cur])
                {
                    return false;
                }

                if (color[neighbor] == -1)
                {
                    color[neighbor] = 1 - color[cur];
                    q.push(neighbor);
                }
            }
        }

        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<vector<int>> g(n + 1);
        for (auto& d : dislikes)
        {
            g[d[0]].push_back(d[1]);
            g[d[1]].push_back(d[0]);
        }

        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; ++i)
        {
            if (color[i] == -1)
            {
                if (!bfs(i, g, color))
                {
                    return false;
                }
            }
        }

        return true;
    }
};
// Runtime 465 ms
// Memory 64.4 MB
// 2022.12.21 at 奥盛大厦